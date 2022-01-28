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

constexpr std::uint32_t NUM_THREADS = 2;
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

int main()
{
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

    return 0;
}
