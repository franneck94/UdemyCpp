#pragma once

#include <cmath>

#include "DynArray.h"

template <typename T>
T sum(DynamicArray<T> &dynamic_array)
{
    auto sum_value = T{};

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
    const auto has_even_length = dynamic_array.get_length() % 2 == 0;

    if (has_even_length)
    {
        const auto index1 = dynamic_array.get_length() / 2;
        const auto index2 = (dynamic_array.get_length() / 2) - 1;
        return (dynamic_array[index1] + dynamic_array[index2]) / 2.0;
    }

    const auto index = dynamic_array.get_length() / 2;
    return dynamic_array[index];
}
