#include <cstdint>
#include <iostream>

#include "exercise.h"

// Exercise 1
double array_sum(const double *p_array, const std::size_t length)
{
    auto sum = 0.0;

    for (std::size_t i = 0; i < length; i++)
    {
        sum += p_array[i];
    }

    return sum;
}

// Exercise 2
std::int32_t *array_constructor(const std::int32_t &value,
                                const std::size_t length)
{
    auto *constructed_array = new std::int32_t[length];

    for (std::size_t i = 0; i < length; i++)
    {
        constructed_array[i] = value;
    }

    return constructed_array;
}
