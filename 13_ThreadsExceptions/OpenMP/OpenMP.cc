#include <algorithm>
#include <assert.h>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include "Timer.h"
#include "omp.h"

constexpr std::uint32_t NUM_THREADS = 8;
constexpr std::uint32_t NUM_RUNS = 200;

template <typename T>
void random_vector(std::vector<T> &vec)
{
    std::mt19937 random_generator(22);
    std::uniform_int_distribution<T> random_distribution(-10, 10);

    for (auto &val : vec)
    {
        val = random_distribution(random_generator);
    }
}

template <typename T>
T serial_sum(std::vector<T> &vec)
{
    T sum = 0;
    T n = static_cast<T>(vec.size());

    for (T i = 0; i != n; ++i)
    {
        sum = sum + vec[i];
    }

    return sum;
}

template <typename T>
T parallel_sum_omp(std::vector<T> &vec)
{
    T final_sum = 0;
    T sum = 0;
    T i = 0;
    T n = static_cast<T>(vec.size());

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

/*
   Serial time in ms: 4.59
2: OpenMP time in ms: 3.31
4: OpenMP time in ms: 2.80
6: OpenMP time in ms: 2.70
8: OpenMP time in ms: 2.71
*/
int main()
{
    // SETUP
    std::vector<std::int32_t> my_vector(30'000'000, 0);
    random_vector(my_vector);

    auto time1 = 0.0;
    volatile std::int32_t sum1 = 0;
    for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
    {
        cpptiming::Timer t1;
        sum1 = serial_sum(my_vector);
        time1 += t1.elapsed_time<cpptiming::millisecs, double>();
    }
    std::cout << "Mean Serial: " << time1 / NUM_RUNS << "ms sum: " << sum1 << std::endl;

    auto time2 = 0.0;
    volatile auto sum2 = 0;
    for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
    {
        cpptiming::Timer t2;
        sum2 = parallel_sum_omp(my_vector);
        time2 += t2.elapsed_time<cpptiming::millisecs, double>();
    }
    std::cout << "Mean OpenMP: " << time2 / NUM_RUNS << "ms sum: " << sum2 << std::endl;

    return 0;
}
