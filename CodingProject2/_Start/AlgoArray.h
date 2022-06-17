#pragma once

#include <cmath>

#include "DynArray.h"

template <typename T>
T sum(DynamicArray<T> &dynamic_array)
{
    T sum_value = 0.0;

    for (std::size_t i = 0; i < dynamic_array.get_length(); i++)
    {
        sum_value += dynamic_array[i];
    }

    return sum_value;
}

template <typename T>
double mean(DynamicArray<T> &dynamic_array)
{
    return sum(dynamic_array) / static_cast<double>(dynamic_array.get_length());
}

template <typename T>
double median(DynamicArray<T> &dynamic_array)
{
    const bool has_even_length = dynamic_array.get_length() % 2 == 0;

    if (has_even_length)
    {
        const std::size_t index1 = dynamic_array.get_length() / 2;
        const std::size_t index2 = (dynamic_array.get_length() / 2) - 1;
        return (dynamic_array[index1] + dynamic_array[index2]) / 2.0;
    }

    const std::size_t index = dynamic_array.get_length() / 2;
    return dynamic_array[index];
}
