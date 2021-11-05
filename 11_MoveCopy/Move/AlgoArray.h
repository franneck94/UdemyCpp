#pragma once

#include <cmath>

#include "DynArray.h"

/**
 * @brief
 *
 * @param dynamic_array
 * @return T
 */
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

/**
 * @brief
 *
 * @param dynamic_array
 * @return double
 */
template <typename T>
double mean(DynamicArray<T> &dynamic_array)
{
    return sum(dynamic_array) / static_cast<double>(dynamic_array.get_length());
}

/**
 * @brief
 *
 * @param dynamic_array
 * @return double
 */
template <typename T>
double median(DynamicArray<T> &dynamic_array)
{
    double median_value = 0.0;
    bool has_odd_length = static_cast<bool>(dynamic_array.get_length() % 2);

    if (has_odd_length)
    {
        std::size_t index = dynamic_array.get_length() / 2;
        median_value = dynamic_array[index];
    }
    else
    {
        std::size_t index1 = dynamic_array.get_length() / 2;
        std::size_t index2 = index1 - 1;
        median_value = (dynamic_array[index1] + dynamic_array[index2]) / 2.0;
    }

    return median_value;
}

/**
 * @brief
 *
 * @param dynamic_array
 * @return double
 */
template <typename T>
double variance(DynamicArray<T> &dynamic_array)
{
    double mean_value = mean(dynamic_array);
    double variance_value = 0.0;
    double probability = 1.0 / static_cast<double>(dynamic_array.get_length());

    for (std::size_t i = 0; i < dynamic_array.get_length(); i++)
    {
        double x_i = dynamic_array[i];
        variance_value += pow(x_i - mean_value, 2.0) * probability;
    }

    return variance_value;
}

/**
 * @brief
 *
 * @param dynamic_array
 * @return double
 */
template <typename T>
double stddev(DynamicArray<T> &dynamic_array)
{
    double variance_value = variance(dynamic_array);
    double stddev_value = sqrt(variance_value);

    return stddev_value;
}
