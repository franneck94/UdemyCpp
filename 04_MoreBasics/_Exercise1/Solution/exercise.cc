#include <cstdint>
#include <iostream>

#include "exercise.h"

namespace computation
{
// Exercise 1
double mean_array_value(int *array, const std::size_t length)
{
    double mean_value = 0.0;

    for (std::uint32_t i = 0; i < length; i++)
    {
        mean_value += array[i];
    }

    mean_value /= length;

    return mean_value;
}

double mean_array_value(double *array, const std::size_t length)
{
    double mean_value = 0.0;

    for (std::uint32_t i = 0; i < length; i++)
    {
        mean_value += array[i];
    }

    mean_value /= length;

    return mean_value;
}
} // namespace computation
