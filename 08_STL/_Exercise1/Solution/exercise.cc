#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "exercise.h"

// Exercise 2
BinaryArray shuffle_till_equal(const BinaryArray &target, BinaryArray input)
{
    auto is_equal = false;
    auto iteration_idx = 1U;

    while (!is_equal)
    {
        if (iteration_idx % 250000 == 0)
        {
            std::cout << '\n' << "Iteration: " << iteration_idx;
        }
        ++iteration_idx;

        std::shuffle(input.begin(),
                     input.end(),
                     std::default_random_engine{42});

        if (std::equal(input.begin(), input.end(), target.begin()))
        {
            is_equal = true;
        }
    }

    return input;
}

// Exercise 3
BinaryArray smart_shuffle_till_equal(const BinaryArray &target,
                                     BinaryArray input)
{
    auto iteration_idx = 1U;

    auto first = input.begin();
    auto last = input.end();

    while (true)
    {
        if (iteration_idx % 100000 == 0)
        {
            std::cout << '\n' << "Iteration: " << iteration_idx;
        }

        while (first != last &&
               *first == target[std::distance(input.begin(), first)])
        {
            ++first;
        }

        if (first == last)
        {
            break;
        }

        std::shuffle(first, last, std::default_random_engine{42});
        ++iteration_idx;
    }

    return input;
}
