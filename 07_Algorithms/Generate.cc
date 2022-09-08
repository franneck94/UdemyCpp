#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using ClockType = std::chrono::steady_clock;
using ClockRes = std::chrono::microseconds;

constexpr static auto NUM_ELEMENTS = 1'000'000U;

std::int32_t gen()
{
    static auto seed = std::random_device{};
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    return dist(gen);
}

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);

    const auto start_time = ClockType::now();
    std::generate(my_vector.begin(), my_vector.end(), gen);
    const auto end_time = ClockType::now();

    const auto elapsed_time =
        std::chrono::duration_cast<ClockRes>(end_time - start_time).count();
    std::cout << "Elapsed time: " << elapsed_time << '\n';

    return 0;
}
