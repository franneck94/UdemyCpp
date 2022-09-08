#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using ClockType = std::chrono::steady_clock;
using ClockRes = std::chrono::microseconds;

constexpr static auto NUM_ELEMENTS = 1'000'000U;

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);

    auto seed = std::random_device{};
    auto gen = std::mt19937{seed()};
    auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    const auto start_time = ClockType::now();
    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        my_vector[i] = dist(gen);
    }
    const auto end_time = ClockType::now();

    const auto elapsed_time =
        std::chrono::duration_cast<ClockRes>(end_time - start_time).count();
    std::cout << "Elapsed time: " << elapsed_time << '\n';

    return 0;
}
