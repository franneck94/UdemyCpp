#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "exercise.h"

// Exercise 2
std::vector<bool> shuffle_till_equal(const BinaryArray &target,
                                     BinaryArray input)
{
    auto equal = false;
    auto iteration = 1U;

    while (!equal)
    {
        if (iteration % 250000 == 0)
        {
            std::cout << '\n' << "Iteration: " << iteration;
        }
        ++iteration;

        std::shuffle(input.begin(),
                     input.end(),
                     std::default_random_engine{42});

        if (std::equal(input.begin(), input.end(), target.begin()))
        {
            equal = true;
        }
    }

    return input;
}

// Exercise 3
std::vector<bool> smart_shuffle_till_equal(const BinaryArray &target,
                                           BinaryArray input)
{
    auto iteration = 1U;

    auto first = input.begin();
    auto last = input.end();

    while (true)
    {
        if (iteration % 100000 == 0)
        {
            std::cout << '\n' << "Iteration: " << iteration;
        }

        while (first != last &&
               *first == target[std::distance(input.begin(), first)])
            ++first;

        if (first == last)
            break;

        std::shuffle(first, last, std::default_random_engine{42});
        ++iteration;
    }

    return input;
}
