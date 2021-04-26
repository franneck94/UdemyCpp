#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>

#include "exercise.h"

// Aufgabe 2
std::vector<bool> shuffle_till_equal(const BinaryArray &target, BinaryArray input)
{
    bool equal = false;
    int iteration = 1;

    while (!equal)
    {
        if (iteration % 250000 == 0)
        {
            std::cout << std::endl << "Iteration: " << iteration;
        }
        ++iteration;

        auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
        std::shuffle(input.begin(), input.end(), std::default_random_engine(timestamp));

        if (std::equal(input.begin(), input.end(), target.begin()))
        {
            equal = true;
        }
    }

    return input;
}

// Aufgabe 3
std::vector<bool> smart_shuffle_till_equal(const BinaryArray &target, BinaryArray input)
{
    bool equal = false;
    std::vector<bool>::iterator first = input.begin();
    std::vector<bool>::iterator last = input.end();
    int iteration = 1;

    while (!equal)
    {
        if (iteration % 100000 == 0)
        {
            std::cout << std::endl << "Iteration: " << iteration;
        }
        ++iteration;

        auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
        std::shuffle(first, last, std::default_random_engine(timestamp));

        int index = std::distance(input.begin(), first);

        if (*first == target[index])
            ++first;

        if (first == last)
            equal = true;
    }

    return input;
}
