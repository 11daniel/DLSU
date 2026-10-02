// ocr_demo.cpp
// Single Producer–Consumer image cleaner (Leptonica)
// C++20

#include <leptonica/allheaders.h>

#include <condition_variable>
#include <filesystem>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <string>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

// ------------ Thread-safe bounded queue of file paths ------------
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

// -------------- Small helpers --------------
static bool has_image_ext(const fs::path& p) {
    if (!p.has_extension()) return false;
    std::string e = p.extension().string();
    for (auto& c : e) c = (char)std::tolower(c);
    return e == ".png" || e == ".jpg" || e == ".jpeg" ||
           e == ".tif" || e == ".tiff" || e == ".bmp";
}

// Clean & binarize with a lightweight pipeline.
// You can tweak kernel sizes/parameters to suit your dataset.
static Pix* clean_and_binarize(Pix* src8) {
    // src8 must be 8bpp gray
    // 1) Gentle opening to remove tiny specks
    Pix* opened = pixOpenGray(src8, 3, 3);          // new Pix
    // 2) Gentle closing to fill tiny gaps in strokes
    Pix* closed = pixCloseGray(opened, 3, 3);       // new Pix
    pixDestroy(&opened);

    // 3) Sauvola binarization (adaptive thresholding)
    Pix* bin = nullptr;
    // winsize=45, factor=0.01 works well for text; tile sizes kept 1x1
    pixSauvolaBinarizeTiled(closed, 45, 0.01, 1, 1, nullptr, &bin);
    pixDestroy(&closed);

    // Optional: remove tiny CCs (salt noise). Keep components >= 15x15 pixels area-ish.
    // This is conservative so we don't erase punctuation.
    Pix* cleaned = pixSelectBySize(bin, 15, 15, 8, L_SELECT_IF_EITHER,
                                   L_SELECT_IF_GTE, nullptr);
    if (cleaned) {
        pixDestroy(&bin);
        bin = cleaned;
    }
    return bin; // caller owns
}

// -------------- Producer --------------
static void producer(PathQueue& q, const fs::path& input_dir) {
    size_t count = 0;
    try {
        for (auto const& entry : fs::directory_iterator(input_dir)) {
            if (!entry.is_regular_file()) continue;
            if (!has_image_ext(entry.path())) continue;
            q.push(entry.path());
            ++count;
        }
    } catch (const std::exception& e) {
        std::cerr << "[Producer] Error: " << e.what() << "\n";
    }
    q.close();
    std::cout << "[Producer] Enqueued " << count << " image(s).\n";
}

// -------------- Consumer --------------
static void consumer(PathQueue& q, const fs::path& out_dir) {
    fs::create_directories(out_dir);

    size_t done = 0, failed = 0;
    for (;;) {
        auto item = q.pop();
        if (!item) break;  // queue closed & empty
        const fs::path& in_path = *item;

        // Load
        Pix* src = pixRead(in_path.string().c_str());
        if (!src) {
            std::cerr << "[Consumer] Failed to read: " << in_path << "\n";
            ++failed;
            continue;
        }

        // Ensure 8bpp grayscale
        Pix* gray = (pixGetDepth(src) == 8) ? pixClone(src) : pixConvertTo8(src, 0);
        pixDestroy(&src);

        if (!gray) {
            std::cerr << "[Consumer] Grayscale convert failed: " << in_path << "\n";
            ++failed;
            continue;
        }

        Pix* bin = clean_and_binarize(gray);
        pixDestroy(&gray);

        if (!bin) {
            std::cerr << "[Consumer] Binarization failed: " << in_path << "\n";
            ++failed;
            continue;
        }

        // Output filename: <name>_bin.png
        fs::path out_path = out_dir / (in_path.stem().string() + "_bin.png");
        if (pixWrite(out_path.string().c_str(), bin, IFF_PNG) != 0) {
            std::cerr << "[Consumer] Write failed: " << out_path << "\n";
            ++failed;
        } else {
            std::cout << "[Consumer] Wrote: " << out_path << "\n";
            ++done;
        }

        pixDestroy(&bin);
    }
    std::cout << "[Consumer] Completed. Success: " << done << ", Failed: " << failed << "\n";
}

// -------------- Main --------------
int main(int argc, char** argv) {
    if (argc < 2 || argc > 4) {
        std::cerr
            << "Usage:\n"
            << "  " << argv[0] << " <input_dir> [output_dir] [queue_capacity]\n\n"
            << "Example:\n"
            << "  " << argv[0] << " ./images ./out 8\n";
        return 1;
    }

    fs::path input_dir = fs::path(argv[1]);
    if (!fs::exists(input_dir) || !fs::is_directory(input_dir)) {
        std::cerr << "Error: input_dir is not a directory: " << input_dir << "\n";
        return 1;
    }

    fs::path output_dir = (argc >= 3) ? fs::path(argv[2]) : (input_dir / "cleaned");
    size_t cap = (argc >= 4) ? static_cast<size_t>(std::stoul(argv[3])) : 8;
    if (cap == 0) cap = 1;

    PathQueue queue(cap);

    std::thread prod(producer, std::ref(queue), std::cref(input_dir));
    std::thread cons(consumer, std::ref(queue), std::cref(output_dir));

    prod.join();
    cons.join();
    return 0;
}
