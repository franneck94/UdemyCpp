#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using ClockType = std::chrono::steady_clock;
using ClockRes = std::chrono::microseconds;

constexpr static auto NUM_ELEMENTS = 1'000'000U;

std::int32_t gen()
{
    static auto seed_generator = std::random_device{};
    static auto random_generator = std::mt19937_64{seed_generator()};
    static auto random_distribution =
        std::uniform_int_distribution<std::int32_t>{-10, 10};

    return random_distribution(random_generator);
}

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0);

    const auto start_time = ClockType::now();
    std::generate(my_vector.begin(), my_vector.end(), gen);
    const auto end_time = ClockType::now();

    const auto elapsed_time_ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time)
            .count();
    const auto elapsed_time_us =
        std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time)
            .count();
    const auto elapsed_time_ns =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time)
            .count();

    std::cout << "Elapsed time ms: " << elapsed_time_ms << '\n';
    std::cout << "Elapsed time us: " << elapsed_time_us << '\n';
    std::cout << "Elapsed time ns: " << elapsed_time_ns << '\n';

    return 0;
}
