// ocr_demo.cpp
// Multi-Consumer, Single-Producer OCR Pipeline
// C++20

#include <leptonica/allheaders.h>    // For Leptonica (preprocessing)
#include <tesseract/baseapi.h>    // For Tesseract (inference)

#include <atomic>                 // For std::atomic (sequential ID)
#include <chrono>                 // For timing
#include <condition_variable>
#include <filesystem>
#include <fstream>                // For std::ofstream (CSV output)
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <semaphore>              // For std::binary_semaphore
#include <sstream>                // For std::stringstream
#include <string>
#include <thread>
#include <vector>
#include <algorithm>              // For std::sort

namespace fs = std::filesystem;

// ------------ Thread-safe bounded queue of file paths (Unchanged) ------------
class PathQueue {
public:
    explicit PathQueue(size_t cap) : cap_(cap) {}

    void push(fs::path p) {
        std::unique_lock<std::mutex> lk(m_);
        cv_not_full_.wait(lk, [&]{ return q_.size() < cap_ || done_; });
        if (done_) return;               // stop accepting if closed
        q_.push(std::move(p));
        cv_not_empty_.notify_one();
    }

    // Signal that producer is finished; consumer drains remaining items
    void close() {
        std::lock_guard<std::mutex> lk(m_);
        done_ = true;
        cv_not_empty_.notify_all();
        cv_not_full_.notify_all();
    }

    // Pop; returns std::nullopt when closed *and* empty
    std::optional<fs::path> pop() {
        std::unique_lock<std::mutex> lk(m_);
        cv_not_empty_.wait(lk, [&]{ return !q_.empty() || done_; });
        if (q_.empty()) return std::nullopt;
        fs::path p = std::move(q_.front());
        q_.pop();
        cv_not_full_.notify_one();
        return p;
    }

private:
    std::mutex m_;
    std::condition_variable cv_not_empty_, cv_not_full_;
    std::queue<fs::path> q_;
    size_t cap_;
    bool done_ = false;
};

// ----------------- Shared Resources for Workers -----------------

// For writing to the single CSV file
std::ofstream g_csv_file; 
// Binary semaphore to ensure only one thread writes to the CSV at a time
// This satisfies the requirement to use a semaphore
std::binary_semaphore g_csv_semaphore{1}; 

// Atomic counter for sequential IDs in the CSV
std::atomic<int> g_id_counter{1};

// -------------- Small helpers (Unchanged) --------------
static bool has_image_ext(const fs::path& p) {
    if (!p.has_extension()) return false;
    std::string e = p.extension().string();
    for (auto& c : e) c = (char)std::tolower(c);
    return e == ".png" || e == ".jpg" || e == ".jpeg" ||
           e == ".tif" || e == ".tiff" || e == ".bmp";
}

// Clean & binarize with a median filter, tuned for salt-and-pepper noise.
// ***** THIS IS THE UPDATED FUNCTION *****
static Pix* clean_and_binarize(Pix* src8) {
    // src8 must be 8bpp gray

    // 1) Apply a Median Filter (Rank Filter with 0.5 rank).
    // This is the correct and most effective tool for removing
    // "salt and pepper" noise (both black specks and white holes)
    // without significantly damaging the main letter shapes.
    // We use a 3x3 kernel for a gentle filtering.
    Pix* filtered = pixRankFilterGray(src8, 3, 3, 0.5);
    if (!filtered) {
        // Fallback if filtering fails
        filtered = pixClone(src8);
    }

    // 2) Sauvola binarization (adaptive thresholding)
    // We binarize the *filtered* image.
    // The parameters (45, 0.01) are good for general text.
    Pix* bin = nullptr;
    pixSauvolaBinarizeTiled(filtered, 45, 0.01, 1, 1, nullptr, &bin);
    pixDestroy(&filtered); // Clean up the intermediate filtered image

    if (!bin) {
        // Binarization failed, return null
        return nullptr;
    }

    // 3) Keep only components of a reasonable size.
    // This is the "Connected Component Analysis" step to remove noise.
    //
    // The original (15, 15) was too large and was deleting
    // parts of your words.
    //
    // We will keep components that are at least 4 pixels wide OR 4 pixels high.
    // This will discard tiny noise specks while "retaining the original word".
    Pix* selected = pixSelectBySize(bin, 4, 4, 8, L_SELECT_IF_EITHER,
                                    L_SELECT_IF_GTE, nullptr);

    if (selected) {
        pixDestroy(&bin); // destroy the noisy binary image
        bin = selected;   // keep the selected (clean) one
    }

    return bin; // caller owns
}

// Helper to format text for CSV (escapes quotes)
static std::string escape_csv(const std::string& s) {
    std::string_view sv = s;
    // Trim leading/trailing whitespace/newlines
    sv.remove_prefix(std::min(sv.find_first_not_of(" \t\n\r"), sv.length()));
    sv.remove_suffix(std::min(sv.length() - sv.find_last_not_of(" \t\n\r") - 1, sv.length()));

    static const std::string_view chars_to_skip = "*:'/;{}[].,|~-_<>`~^—’‘“";

    std::stringstream ss;
    for (char c : sv) {

        if (chars_to_skip.find(c) != std::string_view::npos) {
            continue; // Skip this character
        }

        ss << c;
        if (c == '"') {
            ss << '"'; // Escape " by doubling to ""
        }
    }
    return ss.str();
}


// -------------- Producer (MODIFIED FOR SORTING) --------------
// This is the "Main Thread" task of loading images
// ***** THIS IS THE UPDATED FUNCTION *****
static void producer(PathQueue& q, const fs::path& input_dir) {
    std::vector<fs::path> paths; // 1. Create a vector to hold paths
    
    try {
        // 2. Collect all valid image paths
        for (auto const& entry : fs::directory_iterator(input_dir)) {
            if (!entry.is_regular_file()) continue;
            if (!has_image_ext(entry.path())) continue;
            paths.push_back(entry.path());
        }
    } catch (const std::exception& e) {
        std::cerr << "[Producer] Error: " << e.what() << "\n";
    }

    // 3. Sort the paths alphabetically
    std::sort(paths.begin(), paths.end());

    // 4. Push the sorted paths into the queue
    for (const auto& p : paths) {
        q.push(p);
    }

    q.close(); // Signal to consumers that no more items are coming
    std::cout << "[Producer] Enqueued " << paths.size() << " image(s) in order.\n";
}

// -------------- Consumer (Heavily Modified) --------------
// This is the "Worker Thread" task
static void worker_thread(int id, PathQueue& q) {
    // Each thread initializes its own Tesseract API instance
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract for English.
    // Make sure you have 'eng.traineddata' in your tessdata directory!
    if (api->Init(nullptr, "eng")) {
        std::cerr << "[Worker " << id << "] Could not initialize tesseract." << std::endl;
        return;
    }

    size_t done = 0, failed = 0;
    for (;;) {
        auto item = q.pop();
        if (!item) break;  // queue closed & empty
        
        const fs::path& in_path = *item;

        // Start timing this specific job
        auto start_time = std::chrono::high_resolution_clock::now();

        // 1. Load
        Pix* src = pixRead(in_path.string().c_str());
        if (!src) {
            std::cerr << "[Worker " << id << "] Failed to read: " << in_path << "\n";
            ++failed;
            continue;
        }

        // 2. Preprocessing
        Pix* gray = (pixGetDepth(src) == 8) ? pixClone(src) : pixConvertTo8(src, 0);
        pixDestroy(&src);
        if (!gray) {
            std::cerr << "[Worker " << id << "] Grayscale convert failed: " << in_path << "\n";
            ++failed;
            continue;
        }

        Pix* bin = clean_and_binarize(gray); // Preprocessing
        pixDestroy(&gray);
        if (!bin) {
            std::cerr << "[Worker " << id << "] Binarization failed: " << in_path << "\n";
            ++failed;
            continue;
        }

        // 3. Inference
        api->SetImage(bin); // Give the preprocessed image to Tesseract
        char* outText = api->GetUTF8Text();
        std::string extracted_text(outText ? outText : "");
        
        // Clean up Tesseract/Leptonica resources
        delete [] outText;
        pixDestroy(&bin);
        api->Clear(); // Clear adaptive classifier for next image

        // 4. Stop timing
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

        // 5. Write to shared CSV file
        
        // Get a sequential ID atomically
        int sequential_id = g_id_counter.fetch_add(1); 
        std::string filename = in_path.filename().string();
        std::string csv_text = escape_csv(extracted_text);

        // Acquire the semaphore to safely write to the file
        g_csv_semaphore.acquire();
        try {
            g_csv_file << sequential_id << ",\"" 
                       << filename << "\",\"" 
                       << csv_text << "\"," 
                       << duration_ms << "ms\n";
        } catch (const std::exception& e) {
            std::cerr << "[Worker " << id << "] Failed to write to CSV: " << e.what() << "\n";
        }
        g_csv_semaphore.release(); // Release the semaphore

        ++done;
    }

    // Clean up this thread's Tesseract instance
    api->End();
    delete api;

    std::cout << "[Worker " << id << "] Completed. Success: " << done << ", Failed: " << failed << "\n";
}

// -------------- Main (Heavily Modified) --------------
int main() {
    // Prompt user for input directory
    std::string input_path_str;
    std::cout << "Enter the directory of images to be processed: ";
    std::getline(std::cin, input_path_str);

    fs::path input_dir(input_path_str);
    if (!fs::exists(input_dir) || !fs::is_directory(input_dir)) {
        std::cerr << "Error: input_dir is not a directory: " << input_dir << "\n";
        return 1;
    }

    // Prompt user for number of worker threads
    int num_workers = 0;
    while (num_workers < 2) {
        std::cout << "Enter number of worker threads (at least 2): "; //
        std::cin >> num_workers;
        if (num_workers < 2) {
            std::cout << "Must use at least two worker threads.\n";
        }
    }
    
    // Set queue capacity. A good heuristic is 2x the number of workers.
    size_t cap = num_workers * 2;
    PathQueue queue(cap);

    // Open the single CSV file and write the header
    try {
        g_csv_file.open("result.csv");
        g_csv_file << "ID,Image,Text,Processing Time\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: Could not open result.csv for writing: " << e.what() << "\n";
        return 1;
    }

    std::cout << "Starting pipeline with 1 producer and " << num_workers << " workers...\n";
    std::vector<std::thread> workers;

    // Start the producer thread
    std::thread prod(producer, std::ref(queue), std::cref(input_dir));

    // Start all the worker threads
    for (int i = 0; i < num_workers; ++i) {
        workers.emplace_back(worker_thread, i, std::ref(queue));
    }

    // Wait for all threads to finish
    prod.join();
    for (auto& t : workers) {
        t.join();
    }

    // All threads are done, close the file
    g_csv_file.close();

    std::cout << "All images processed. Results saved to result.csv.\n"; //
    return 0;
}