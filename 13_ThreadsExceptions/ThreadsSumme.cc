#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <string>
#include <thread>
#include <vector>

#include "omp.h"

using std::string;
using std::vector;

template <typename T> long long serial_sum(vector<T> &vec)
{
    long long sum = 0;

    for (int i = 0; i != vec.size(); ++i)
    {
        sum += vec[i];
    }

    return sum;
}

template <typename T> long long adder(vector<T> vec, size_t begin, size_t end)
{
    long long sum = 0;

    for (int i = begin; i != end; ++i)
    {
        sum += vec[i];
    }

    return sum;
}

long long parallel_sum(vector<int> &vec)
{
    int n_threads = std::thread::hardware_concurrency();
    size_t length = std::distance(vec.begin(), vec.end());
    size_t elements_per_thread = length / n_threads;
    size_t begin = 0;
    size_t end = elements_per_thread;
    long long final_sum = 0;

    vector<long long> sums(n_threads);
    vector<std::thread> threads(n_threads - 1);

    for (int i = 0; i != threads.size(); ++i)
    {
        threads[i] = std::thread([&](long long sum) { sum = adder(vec, begin, end); }, std::ref(sums[i]));

        begin = end;
        end = end + elements_per_thread;
    }

    sums[n_threads - 1] = adder(vec, begin, end);

    for (int i = 0; i != threads.size(); ++i)
    {
        threads[i].join();
    }

    final_sum = adder(sums, 0, sums.size());
    return final_sum;
}

int main()
{
    // SETUP
    std::random_device gen;
    std::uniform_int_distribution<int> dist(-10, 10);
    vector<int> vector_a(10'000'000, 0);
    std::generate(vector_a.begin(), vector_a.end(), [&]() { return dist(gen); });

    // SERIELL
    auto start = std::chrono::high_resolution_clock::now();
    long long sum_vector = serial_sum(vector_a);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = end - start;
    std::cout << std::endl << "Serial time in ms: " << ms.count();
    std::cout << std::endl << "Serial Sum: " << sum_vector << std::endl;

    // PARALLEL
    start = std::chrono::high_resolution_clock::now();
    sum_vector = parallel_sum(vector_a);
    end = std::chrono::high_resolution_clock::now();
    ms = end - start;
    std::cout << std::endl << "Parallel time in ms: " << ms.count();
    std::cout << std::endl << "Parallel Sum: " << sum_vector << std::endl;

    // REDUCE
    start = std::chrono::high_resolution_clock::now();
    sum_vector = std::reduce(vector_a.begin(), vector_a.end());
    end = std::chrono::high_resolution_clock::now();
    ms = end - start;
    std::cout << std::endl << "Reduce time in ms: " << ms.count();
    std::cout << std::endl << "Reduce Sum: " << sum_vector << std::endl;

    // ACCUMULATE
    start = std::chrono::high_resolution_clock::now();
    sum_vector = std::accumulate(vector_a.begin(), vector_a.end(), 0, std::plus<int>());
    end = std::chrono::high_resolution_clock::now();
    ms = end - start;
    std::cout << std::endl << "Accumulate time in ms: " << ms.count();
    std::cout << std::endl << "Accumulate Sum: " << sum_vector << std::endl;

    return 0;
}