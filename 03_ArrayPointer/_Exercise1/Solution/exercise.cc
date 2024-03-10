#include <array>
#include <cstddef>
#include <cstdint>

#include "exercise.h"

// Exercise 2
double array_sum(const double array[], const std::size_t length)
{
    auto sum = 0.0;

    for (std::size_t i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum;
}

// Exercise 3
double array_sum(const std::array<double, 100> array)
{
    auto sum = 0.0;

    for (std::size_t i = 0; i < array.size(); i++)
    {
        sum += array[i];
    }

    return sum;
}
