#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <thread>

#include "Timer.h"

constexpr std::uint32_t NUM_THREADS = 3;

void function(const std::int32_t input, std::int32_t &output)
{
    output = input * 2;
}

int main()
{
    std::array<std::thread, NUM_THREADS> threads;
    std::array<std::int32_t, NUM_THREADS> inputs{};
    std::array<std::int32_t, NUM_THREADS> outputs{};

    std::iota(inputs.begin(), inputs.end(), 0);
    std::fill(outputs.begin(), outputs.end(), 0);

    cpptiming::Timer timer;

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i] = std::thread(function, inputs[i], std::ref(outputs[i]));
    }

    // ...

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i].join();
    }

    auto time_us = timer.elapsed_time<cpptiming::microsecs, double>();
    std::cout << "Time in us: " << time_us << '\n';

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        std::cout << "Outputs[" << i << "] = " << outputs[i] << '\n';
    }

    return 0;
}
