#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <thread>

namespace
{
constexpr auto NUM_THREADS = std::uint32_t{3U};

auto GLOBAL_COUNTER = std::uint32_t{0};
constexpr static auto NUM_INCREMENTS = std::uint32_t{100'000};
} // namespace

void function(const std::int32_t input, std::int32_t &output)
{
    output = input * 2;

    for (std::uint32_t i = 0; i < NUM_INCREMENTS; ++i)
    {
        ++GLOBAL_COUNTER;
    }
}

int main()
{
    std::array<std::thread, NUM_THREADS> threads;

    auto inputs = std::array<std::int32_t, NUM_THREADS>{};
    auto outputs = std::array<std::int32_t, NUM_THREADS>{};
    std::iota(inputs.begin(), inputs.end(), 0);

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i] = std::thread(function, inputs[i], std::ref(outputs[i]));
    }

    // ....

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i].join();
    }

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        std::cout << "Input: " << inputs[i] << " and Output: " << outputs[i]
                  << '\n';
    }

    std::cout << "GLOBAL_COUNTER: " << GLOBAL_COUNTER << '\n';

    return 0;
}
