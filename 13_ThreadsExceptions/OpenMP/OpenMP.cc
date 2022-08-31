#include <algorithm>
#include <array>
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
Serial time:      4.569ms
2: Own time:      3.336ms
4: Own time:      3.071ms
6: Own time:      3.008ms
8: Own time:      2.975ms
2: OpenMP time:   2.98ms
4: OpenMP time:   2.599ms
6: OpenMP time:   2.473ms
8: OpenMP time:   2.506ms
*/
constexpr std::uint32_t NUM_THREADS = 8;
constexpr std::uint32_t NUM_RUNS = 1'000;

template <typename T>
void random_vector(std::vector<T> &vec)
{
    constexpr std::int32_t seed = 42;
    constexpr std::int32_t lower_bound = -10;
    constexpr std::int32_t upper_bound = 10;

    std::mt19937 random_generator(seed);
    std::uniform_int_distribution<T> random_distribution(lower_bound, upper_bound);

    for (auto &val : vec)
    {
        val = random_distribution(random_generator);
    }
}

template <typename T>
T serial_sum(std::vector<T> &vec)
{
    T local_sum = 0;
    const auto n = static_cast<std::uint32_t>(vec.size());

    for (std::uint32_t i = 0; i != n; ++i)
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

    std::uint32_t i = 0;
    const auto n = static_cast<std::uint32_t>(vec.size());

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
void sum_slice(It first, It last, T &result)
{
    result = std::accumulate(first, last, T{});
}

template <typename T>
T parallel_sum(std::vector<T> &vec)
{
    T final_sum = 0;
    std::array<T, NUM_THREADS> local_sums{};
    std::array<std::thread, NUM_THREADS> threads;

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

        threads[i] = std::thread(sum_slice<typename std::vector<T>::iterator, T>,
                                 first,
                                 last,
                                 std::ref(local_sums[i]));

        prev_last = prev_last + slice_size;
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    for (const auto local_sum : local_sums)
    {
        final_sum += local_sum;
    }

    return final_sum;
}

int main()
{
    std::vector<std::int32_t> my_vector(30'000'000, 0);
    random_vector(my_vector);

    // auto time1 = 0.0;
    // volatile std::int32_t sum1 = 0;
    // for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
    // {
    //     cpptiming::Timer t1;
    //     sum1 = serial_sum(my_vector);
    //     time1 += t1.elapsed_time<cpptiming::millisecs, double>();
    // }
    // std::cout << "Mean Serial: " << time1 / NUM_RUNS << "ms sum: " << sum1 << std::endl;

    auto time2 = 0.0;
    volatile auto sum2 = 0;
    for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
    {
        cpptiming::Timer t2;
        sum2 = parallel_sum_omp(my_vector);
        time2 += t2.elapsed_time<cpptiming::millisecs, double>();
    }
    std::cout << "Mean OpenMP: " << time2 / NUM_RUNS << "ms sum: " << sum2 << '\n';

    // auto time3 = 0.0;
    // volatile auto sum3 = 0;
    // for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
    // {
    //     cpptiming::Timer t3;
    //     sum3 = parallel_sum(my_vector);
    //     time3 += t3.elapsed_time<cpptiming::millisecs, double>();
    // }
    // std::cout << "Own MT: " << time3 / NUM_RUNS << "ms sum: " << sum3 << std::endl;

    return 0;
}
