#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <execution>
#include <iostream>
#include <numeric>
#include <random>
#include <thread>
#include <vector>

#include "Timer.h"
#include "omp.h"

/*
Serial:         4.400ms
Parallel std:   2.111ms

2: Own:         3.336ms
4: Own:         2.696ms
6: Own:         2.561ms
8: Own:         2.441ms

2: OpenMP:      2.98ms
4: OpenMP:      2.952ms
6: OpenMP:      2.657ms
8: OpenMP:      2.227ms
*/

namespace
{
constexpr auto NUM_THREADS = std::uint32_t{8};
constexpr auto NUM_RUNS = std::uint32_t{1'000};
constexpr static auto NUM_ELEMENTS = std::uint32_t{30'000'000};
} // namespace

template <typename T>
void random_vector(std::vector<T> &vec)
{
    constexpr static auto seed = std::int32_t{42};
    constexpr static auto lower_bound = std::int32_t{-10};
    constexpr static auto upper_bound = std::int32_t{10};

    static auto random_generator = std::mt19937{seed};
    static auto random_distribution =
        std::uniform_int_distribution<T>(lower_bound, upper_bound);

    for (auto &val : vec)
    {
        val = random_distribution(random_generator);
    }
}

template <typename T>
T serial_sum(std::vector<T> &vec)
{
    return std::accumulate(vec.begin(), vec.end(), T{});
}

template <typename T>
T parallel_sum_omp(std::vector<T> &vec)
{
    auto final_sum = T{};
    auto local_sum = T{};

    auto i = std::int32_t{0};
    const auto n = static_cast<std::int32_t>(vec.size());

#pragma omp parallel for reduction(+ : local_sum) num_threads(NUM_THREADS)
    for (i = 0; i < n; ++i)
    {
        local_sum = local_sum + vec[static_cast<size_t>(i)];
    }
#pragma omp critical
    {
        final_sum += local_sum;
    }

    return final_sum;
}

template <typename T>
T parallel_sum_std(std::vector<T> &vec)
{
    return std::reduce(std::execution::par, vec.begin(), vec.end());
}

template <typename T>
T parallel_sum(std::vector<T> &vec)
{
    auto final_sum = T{};
    auto local_sums = std::array<T, NUM_THREADS>{};
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

        threads[i] = std::thread(
            [](auto first_, auto last_, T &result) {
                result = std::accumulate(first_, last_, T{});
            },
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
    static auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0);
    random_vector(my_vector);

    auto time = 0.0;
    volatile auto sum = std::int32_t{0};

    std::cout << "\n\nUsing " << NUM_THREADS << " Threads\n";

    {
        for (std::uint32_t i = 0; i < 20; ++i)
        {
            const auto t = cpptiming::Timer{};
            sum = serial_sum(my_vector);
            time += t.elapsed_time<cpptiming::millisecs, double>();
        }
        std::cout << "Serial: " << time / 20 << "ms sum: " << sum << '\n';
        time = 0.0;
    }

    {
        for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
        {
            const auto t = cpptiming::Timer{};
            sum = parallel_sum_std(my_vector);
            time += t.elapsed_time<cpptiming::millisecs, double>();
        }
        std::cout << "Parallel Std: " << time / NUM_RUNS << "ms sum: " << sum
                  << '\n';
        time = 0.0;
    }

    {
        for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
        {
            const auto t = cpptiming::Timer{};
            sum = parallel_sum(my_vector);
            time += t.elapsed_time<cpptiming::millisecs, double>();
        }
        std::cout << "Parallel: " << time / NUM_RUNS << "ms sum: " << sum
                  << '\n';
        time = 0.0;
    }

    {
        for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
        {
            const auto t = cpptiming::Timer{};
            sum = parallel_sum_omp(my_vector);
            time += t.elapsed_time<cpptiming::millisecs, double>();
        }
        std::cout << "Parallel OpenMP: " << time / NUM_RUNS << "ms sum: " << sum
                  << '\n';
    }

    return 0;
}
