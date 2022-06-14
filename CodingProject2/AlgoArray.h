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
    double median_value = 0.0;
    const auto has_odd_length = static_cast<bool>(dynamic_array.get_length() % 2);

    if (has_odd_length)
    {
        const auto index = dynamic_array.get_length() / 2;
        median_value = dynamic_array[index];
    }
    else
    {
        const auto index1 = dynamic_array.get_length() / 2;
        const auto index2 = index1 - 1;
        median_value = (dynamic_array[index1] + dynamic_array[index2]) / 2.0;
    }

    return median_value;
}
