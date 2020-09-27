#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "omp.h"

long long serial_sum(std::vector<int> &vec)
{
    long long sum = 0;

    for (int i = 0; i != vec.size(); ++i)
    {
        sum = sum + vec[i];
    }

    return sum;
}

/*
  Serial time in ms:  4.0918
2: OpenMP time in ms: 2.93575
4: OpenMP time in ms: 2.48717
6: OpenMP time in ms: 2.3313
8: OpenMP time in ms: 2.25205
*/
long long parallel_sum_omp(std::vector<int> &vec)
{
    long long final_sum = 0;
    long long sum = 0;
    int i = 0;
    int n = vec.size();

    const int NUM_THREADS = 2;
#pragma omp parallel for reduction(+ : sum) num_threads(NUM_THREADS)
    for (i = 0; i < n; ++i)
    {
        sum = sum + vec[i];
    }
#pragma omp critical
    {
        final_sum += sum;
    }

    return final_sum;
}

int main()
{
    // SETUP
    const int NUM_RUNS = 100;
    long long sum_vector = 0L;

    std::random_device gen;
    std::uniform_int_distribution<int> dist(-10, 10);
    std::vector<int> vector_a(10'000'000, 0);
    std::generate(vector_a.begin(), vector_a.end(), [&]() { return dist(gen); });

    // SERIELL
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_RUNS; ++i)
    {
        sum_vector = serial_sum(vector_a);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = end - start;
    std::cout << std::endl << "Serial time in ms: " << ms.count() / NUM_RUNS;
    std::cout << std::endl << "Serial Sum: " << sum_vector << std::endl;

    // OPENMP
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_RUNS; ++i)
    {
        sum_vector = parallel_sum_omp(vector_a);
    }
    end = std::chrono::high_resolution_clock::now();
    ms = end - start;
    std::cout << std::endl << "OpenMP time in ms: " << ms.count() / NUM_RUNS;
    std::cout << std::endl << "OpenMP Sum: " << sum_vector << std::endl;

    return 0;
}