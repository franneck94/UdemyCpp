#pragma once

#include <array>
#include <cstdint>

namespace computation
{
// Exercise 1
template <std::size_t N>
double mean_array_value(std::array<int, N> &array)
{
    double mean_value = 0.0;

    for (std::uint32_t i = 0; i < array.size(); i++)
    {
        mean_value += array[i];
    }

    mean_value /= static_cast<double>(array.size());

    return mean_value;
}

template <std::size_t N>
double mean_array_value(std::array<double, N> &array)
{
    double mean_value = 0.0;

    for (std::uint32_t i = 0; i < array.size(); i++)
    {
        mean_value += array[i];
    }

    mean_value /= static_cast<double>(array.size());

    return mean_value;
}

// Exercise 2
struct Dataset
{
    double mean_array_a;
    double mean_array_b;
};
} // namespace computation
