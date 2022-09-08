#include <chrono>
#include <cstdint>
#include <execution>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using ClockType = std::chrono::steady_clock;
using ClockRes = std::chrono::microseconds;

constexpr static auto NUM_ELEMENTS = 10'000'000U;

std::int32_t gen()
{
    static auto seed = std::random_device{};
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    return dist(gen);
}

void print_vector(const std::vector<std::int32_t> &vec)
{
    for (const auto v : vec)
    {
        std::cout << v << '\n';
    }
    std::cout << '\n';
}

std::int32_t func1(const std::int32_t val1, const std::int32_t val2)
{
    return val1 + val2;
}

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);
    std::generate(my_vector.begin(), my_vector.end(), gen);

    const auto start_time1 = ClockType::now();
    const auto sum1 = std::accumulate(my_vector.begin(), my_vector.end(), 0);
    const auto end_time1 = ClockType::now();
    const auto elapsed_time1 =
        std::chrono::duration_cast<ClockRes>(end_time1 - start_time1).count();
    std::cout << "Elapsed time: " << elapsed_time1 << '\n';
    std::cout << "Sum: " << sum1 << '\n';

    return 0;
}
