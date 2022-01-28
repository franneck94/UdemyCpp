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

int main()
{
    std::vector<std::int32_t> my_vector(30'000'000, 0);
    random_vector(my_vector);

    auto time1 = 0.0;
    volatile std::int32_t sum1 = 0;
    for (std::uint32_t i = 0; i < NUM_RUNS / 10; ++i)
    {
        cpptiming::Timer t1;
        sum1 = serial_sum(my_vector);
        time1 += t1.elapsed_time<cpptiming::millisecs, double>();
    }
    std::cout << "Mean Serial: " << time1 / (NUM_RUNS / 10) << "ms sum: " << sum1 << std::endl;

    return 0;
}
