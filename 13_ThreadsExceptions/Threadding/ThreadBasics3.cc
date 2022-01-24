#include <cstdint>
#include <iostream>
#include <thread>

#include "Timer.h"

constexpr std::uint32_t NUM_THREADS = 3;

void function(const int input, int &output)
{
    printf("Argument: %d\n", input);

    output = input * 2;
}

int main()
{
    std::thread threads[NUM_THREADS];
    std::int32_t inputs[NUM_THREADS]{};
    std::int32_t outputs[NUM_THREADS]{};

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        inputs[i] = i;
        outputs[i] = 0;
    }

    cpptiming::Timer timer;

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i] = std::thread{function, inputs[i], std::ref(outputs[i])};
    }

    // ...

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        threads[i].join();
    }

    std::cout << "Time: " << timer.elapsed_time<cpptiming::microsecs, double>() << "ms." << std::endl;

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        printf("Result: %d\n", outputs[i]);
    }

    return 0;
}
