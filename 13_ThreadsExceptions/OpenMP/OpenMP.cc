#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <random>
#include <thread>
#include <vector>

#include "Timer.h"
#include "omp.h"

/*
   Serial time:   5.00ms
2: OpenMP time:   3.326ms
4: OpenMP time:   2.794ms
6: OpenMP time:   2.763ms
8: OpenMP time:   2.667ms
2: Own time:      3.224ms
4: Own time:      2.571ms
6: Own time:      2.537ms
8: Own time:      2.6360m
*/
constexpr std::uint32_t NUM_THREADS = 2;
constexpr std::uint32_t NUM_RUNS = 1000;

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
    T local_sum = 0;
    T n = static_cast<T>(vec.size());

    for (T i = 0; i != n; ++i)
    {
        local_sum = local_sum + vec[i];
    }

    return local_sum;
}

template <typename T>
T parallel_sum_omp(std::vector<T> &vec)
{
    T final_sum = 0;
    T local_sum = 0;
    T i = 0;
    T n = static_cast<T>(vec.size());

#pragma omp parallel for reduction(+ : local_sum) num_threads(NUM_THREADS)
    for (i = 0; i < n; ++i)
    {
        local_sum = local_sum + vec[i];
    }
#pragma omp critical
    {
        final_sum += local_sum;
    }

    return final_sum;
}

template <typename It, typename T>
void sum_slice(It &first, It &last, T &result)
{
    result = std::accumulate(first, last, T{});
}

template <typename T>
T parallel_sum_own(std::vector<T> &vec)
{
    T final_sum = 0;
    T local_sums[NUM_THREADS]{};
    std::thread threads[NUM_THREADS];

    const auto slice_size = vec.size() / NUM_THREADS;
    auto prev_last = vec.begin();

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        auto first = prev_last;
        auto last = prev_last + slice_size;

        if (i == (NUM_THREADS - 1))
        {
            last = vec.end();
        }

        threads[i] = std::thread{sum_slice, first, last, std::ref(local_sums[i])};

        prev_last = prev_last + slice_size;
    }

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i].join();
    }

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        final_sum += local_sums[i];
    }

    return final_sum;
}

int main()
{
    // SETUP
    std::vector<std::int32_t> my_vector(30'000'001, 0);
    random_vector(my_vector);

    auto time1 = 0.0;
    volatile std::int32_t sum1 = 0;
    for (std::uint32_t i = 0; i < NUM_RUNS / 10; ++i)
    {
        cpptiming::Timer t1;
        sum1 = serial_sum(my_vector);
        time1 += t1.elapsed_time<cpptiming::millisecs, double>();
    }
    std::cout << "Mean Serial: " << time1 / (NUM_RUNS / 10) << "ms local_sum: " << sum1 << std::endl;

    auto time2 = 0.0;
    volatile auto sum2 = 0;
    for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
    {
        cpptiming::Timer t2;
        sum2 = parallel_sum_omp(my_vector);
        time2 += t2.elapsed_time<cpptiming::millisecs, double>();
    }
    std::cout << "Mean OpenMP: " << time2 / NUM_RUNS << "ms local_sum: " << sum2 << std::endl;

    auto time3 = 0.0;
    volatile auto sum3 = 0;
    for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
    {
        cpptiming::Timer t3;
        sum3 = parallel_sum_omp(my_vector);
        time3 += t3.elapsed_time<cpptiming::millisecs, double>();
    }
    std::cout << "Own MT: " << time3 / NUM_RUNS << "ms local_sum: " << sum3 << std::endl;

    return 0;
}
