#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <thread>
#include <vector>

#include "omp.h"

int main()
{
    // SETUP
    std::random_device gen;
    std::uniform_int_distribution<int> dist(-10, 10);
    std::vector<int> vector_a(10'000'000, 0);
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