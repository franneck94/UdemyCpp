#include <array>
#include <cstdint>
#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>

#include "Timer.h"

namespace
{
constexpr auto NUM_THREADS = std::uint32_t{3U};
constexpr static auto NUM_INCREMENTS = std::uint32_t{100'000};

auto GLOBAL_COUNTER = std::uint32_t{0};
auto MUTEX_COUNTER = std::mutex{};
} // namespace

void function(const std::int32_t input, std::int32_t &output)
{
    output = input * 2;

    for (std::uint32_t i = 0; i < NUM_INCREMENTS; ++i)
    {
        auto guard = std::lock_guard<std::mutex>(MUTEX_COUNTER);
        ++GLOBAL_COUNTER;
    }
}

int main()
{
    std::array<std::thread, NUM_THREADS> threads;

    auto inputs = std::array<std::int32_t, NUM_THREADS>{};
    auto outputs = std::array<std::int32_t, NUM_THREADS>{};
    std::iota(inputs.begin(), inputs.end(), 0);

    auto timer = cpptiming::Timer{};

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i] = std::thread(function, inputs[i], std::ref(outputs[i]));
    }

    // ....

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i].join();
    }

    const auto time_us = timer.elapsed_time<cpptiming::microsecs, double>();
    std::cout << "Time: " << time_us << '\n';

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        std::cout << "Input: " << inputs[i] << " and Output: " << outputs[i]
                  << '\n';
    }

    std::cout << "GLOBAL_COUNTER: " << GLOBAL_COUNTER << '\n';

    return 0;
}
