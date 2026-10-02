#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <thread>
#include <mutex>
#include <atomic>
#include <algorithm>
#include <chrono>

using namespace std;

using Matrix = vector<vector<double>>;

// ---- Utility: split lines into tokens ----
static vector<string> splitTokens(const string& s) {
    vector<string> out;
    string token;
    istringstream iss(s);
    while (iss >> token) out.push_back(token);
    return out;
}

// ---- Read two matrices from input.txt separated by a blank line ----
bool readMatrices(const string& path, Matrix& A, Matrix& B) {
    ifstream fin(path);
    if (!fin) return false;

    vector<string> lines;
    string line;
    while (getline(fin, line)) lines.push_back(line);

    // Find first blank line as separator
    int sep = -1;
    for (int i = 0; i < (int)lines.size(); ++i) {
        string t = lines[i];
        // treat as blank if all whitespace
        if (all_of(t.begin(), t.end(), [](unsigned char c) { return isspace(c); })) {
            sep = i;
            break;
        }
    }
    if (sep == -1) {
        cerr << "Error: Missing blank line separator between matrices in input.txt\n";
        return false;
    }

    auto parseBlock = [&](int lo, int hi, Matrix& M)->bool {
        int cols = -1;
        for (int i = lo; i < hi; ++i) {
            if (all_of(lines[i].begin(), lines[i].end(), [](unsigned char c) { return isspace(c); })) continue;
            auto toks = splitTokens(lines[i]);
            if (toks.empty()) continue;
            if (cols == -1) cols = (int)toks.size();
            else if (cols != (int)toks.size()) {
                cerr << "Error: Inconsistent row lengths in a matrix.\n";
                return false;
            }
            vector<double> row;
            row.reserve(cols);
            for (auto& tk : toks) {
                try {
                    row.push_back(stod(tk));
                }
                catch (...) {
                    cerr << "Error: Non-numeric entry found: " << tk << "\n";
                    return false;
                }
            }
            M.push_back(move(row));
        }
        return !M.empty();
        };

    if (!parseBlock(0, sep, A)) return false;
    if (!parseBlock(sep + 1, (int)lines.size(), B)) return false;
    return true;
}

void writeMatrixOneDecimal(const string& path, const Matrix& C) {
    ofstream fout(path);
    if (!fout) {
        cerr << "Error: Cannot open output file.\n";
        return;
    }
    fout.setf(std::ios::fixed);
    fout << setprecision(1);
    for (size_t i = 0; i < C.size(); ++i) {
        for (size_t j = 0; j < C[i].size(); ++j) {
            if (j) fout << ' ';
            fout << C[i][j];
        }
        if (i + 1 < C.size()) fout << "\n";
    }
}

// ---- Standard single-threaded multiply ----
Matrix multiplySequential(const Matrix& A, const Matrix& B) {
    int m = (int)A.size();
    int p = (int)A[0].size();
    int n = (int)B[0].size();

    Matrix C(m, vector<double>(n, 0.0));

    // Cache B by columns to improve locality
    vector<vector<double>> Bcols(n, vector<double>(p));
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < p; ++k)
            Bcols[j][k] = B[k][j];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            const auto& arow = A[i];
            const auto& bcol = Bcols[j];
            double sum = 0.0;
            int k = 0;
            for (; k + 3 < p; k += 4) {
                sum += arow[k] * bcol[k]
                    + arow[k + 1] * bcol[k + 1]
                    + arow[k + 2] * bcol[k + 2]
                    + arow[k + 3] * bcol[k + 3];
            }
            for (; k < p; ++k) sum += arow[k] * bcol[k];
            C[i][j] = sum;
        }
    }
    return C;
}

// ---- Multithreaded multiply: row partitioning ----
Matrix multiplyParallel(const Matrix& A, const Matrix& B, unsigned numThreads) {
    int m = (int)A.size();
    int p = (int)A[0].size();
    int n = (int)B[0].size();

    Matrix C(m, vector<double>(n, 0.0));

    // Precompute B columns for cache-friendly dot products
    vector<vector<double>> Bcols(n, vector<double>(p));
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < p; ++k)
            Bcols[j][k] = B[k][j];

    if (numThreads == 0) numThreads = 1;
    numThreads = min<unsigned>(numThreads, max(1, m)); // no more threads than rows

    vector<thread> pool;
    pool.reserve(numThreads);

    auto worker = [&](int rowStart, int rowEnd) {
        for (int i = rowStart; i < rowEnd; ++i) {
            const auto& arow = A[i];
            for (int j = 0; j < n; ++j) {
                const auto& bcol = Bcols[j];
                double sum = 0.0;
                int k = 0;
                for (; k + 7 < p; k += 8) {
                    sum += arow[k] * bcol[k]
                        + arow[k + 1] * bcol[k + 1]
                        + arow[k + 2] * bcol[k + 2]
                        + arow[k + 3] * bcol[k + 3]
                        + arow[k + 4] * bcol[k + 4]
                        + arow[k + 5] * bcol[k + 5]
                        + arow[k + 6] * bcol[k + 6]
                        + arow[k + 7] * bcol[k + 7];
                }
                for (; k < p; ++k) sum += arow[k] * bcol[k];
                C[i][j] = sum; // each thread writes unique row i → no locking
            }
        }
        };

    int base = m / numThreads, rem = m % numThreads;
    int cur = 0;
    for (unsigned t = 0; t < numThreads; ++t) {
        int take = base + (t < (unsigned)rem ? 1 : 0);
        int lo = cur, hi = cur + take;
        cur = hi;
        pool.emplace_back(worker, lo, hi);
    }
    for (auto& th : pool) th.join();

    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Matrix A, B;
    if (!readMatrices("input.txt", A, B)) {
        cerr << "Failed to read matrices from input.txt\n";
        return 1;
    }

    // Basic validations
    if (A.empty() || B.empty()) {
        cerr << "Error: One or both matrices are empty.\n";
        return 1;
    }
    int m = (int)A.size();
    int pA = (int)A[0].size();
    int pB = (int)B.size();
    int n = (int)B[0].size();

    if (pA != pB) {
        cerr << "Error: Incompatible dimensions: A is " << m << "x" << pA
            << ", B is " << pB << "x" << n << "\n";
        return 1;
    }
    if (m > 1000 || pA > 1000 || pB > 1000 || n > 1000) {
        cerr << "Error: Matrix dimension exceeds 1000x1000 limit.\n";
        return 1;
    }

    // Time the standard version
    auto t1 = chrono::high_resolution_clock::now();
    Matrix C_std = multiplySequential(A, B);
    auto t2 = chrono::high_resolution_clock::now();
    auto us_std = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    // Time the multithreaded version
    unsigned th = thread::hardware_concurrency();
    if (th == 0) th = 4; // sensible default
    auto t3 = chrono::high_resolution_clock::now();
    Matrix C_par = multiplyParallel(A, B, th);
    auto t4 = chrono::high_resolution_clock::now();
    auto us_par = chrono::duration_cast<chrono::microseconds>(t4 - t3).count();

    // Print timings (microseconds)
    cout << "Standard Running time: " << us_std << " \xCE\xBCs\n";
    cout << "Multithreaded Running time: " << us_par << " \xCE\xBCs\n";

    // Write multithreaded result
    writeMatrixOneDecimal("output.txt", C_par);

    return 0;
}
