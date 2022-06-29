#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using ClockType = std::chrono::steady_clock;
using ClockRes = std::chrono::microseconds;

constexpr std::size_t NUM_ELEMENTS = 1'000'000;

int main()
{
    std::vector<int> my_vector(NUM_ELEMENTS, 0);

    std::random_device seed_generator{};
    std::mt19937_64 random_generator{seed_generator()};
    std::uniform_int_distribution<int> random_distribution{-10, 10};

    auto start_time = ClockType::now();

    for (std::size_t i = 0; i < NUM_ELEMENTS; i++)
    {
        my_vector[i] = random_distribution(random_generator);
    }

    auto end_time = ClockType::now();

    auto elapsed_time_ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time)
            .count();
    auto elapsed_time_us =
        std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time)
            .count();
    auto elapsed_time_ns =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time)
            .count();

    std::cout << "Elapsed time ms: " << elapsed_time_ms << std::endl;
    std::cout << "Elapsed time us: " << elapsed_time_us << std::endl;
    std::cout << "Elapsed time ns: " << elapsed_time_ns << std::endl;

    return 0;
}
