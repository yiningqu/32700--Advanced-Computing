#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

double dotProductSequential(const std::vector<double>& v1, const std::vector<double>& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

void workerFunction(const std::vector<double>& v1, const std::vector<double>& v2, double& result, size_t start, size_t end) {
    double sum = 0.0;
    for (size_t i = start; i < end; i++) {
        sum += v1[i] * v2[i];
    }
    result = sum;
}

double dotProductMultithreaded(const std::vector<double>& v1, const std::vector<double>& v2, int numThreads) {
    double result = 0.0;
    std::vector<std::thread> threads;
    std::vector<double> partialResults(numThreads, 0.0);

    size_t partSize = v1.size() / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        size_t start = i * partSize;
        size_t end = (i == numThreads - 1) ? v1.size() : start + partSize;
        threads.push_back(
                std::thread(workerFunction, std::ref(v1), std::ref(v2), std::ref(partialResults[i]), start, end));
    }
    for (auto &th: threads) {
        th.join();
    }

    for (double val: partialResults) {
        result += val;
    }

    return result;
}


int main(){
    const int N = 1000000;

    std::vector<double> v1(N, 1.0);
    std::vector<double> v2(N, 1.0);

    auto start = std::chrono::high_resolution_clock::now();
    double resultSeq = dotProductSequential(v1, v2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Sequential Result: " << resultSeq << " in " << elapsed.count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    double resultMulti = dotProductMultithreaded(v1, v2, 2); // using 2 threads
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Multithreaded Result: " << resultMulti << " in " << elapsed.count() << " ms" << std::endl;

}
