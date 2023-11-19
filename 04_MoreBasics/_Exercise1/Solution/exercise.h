#pragma once

#include <cstdint>

namespace computation
{
// Exercise 1
double mean_array_value(int *array, const std::size_t length);
double mean_array_value(double *array, const std::size_t length);

// Exercise 2
struct Dataset
{
    double mean_array_a;
    double mean_array_b;
};
} // namespace computation
