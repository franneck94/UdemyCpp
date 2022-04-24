#pragma once

#include "DynArray.h"

/**
 * @brief Computes the sum.
 *
 * @param dynamic_array
 * @return double
 */
double sum(const DynamicArray &dynamic_array);

/**
 * @brief Computes the mean.
 *
 * @param dynamic_array
 * @return double
 */
double mean(const DynamicArray &dynamic_array);

/**
 * @brief Computes the median.
 *
 * @param dynamic_array
 * @return double
 */
double median(const DynamicArray &dynamic_array);

/**
 * @brief Computes the variance.
 *
 * @param dynamic_array
 * @return double
 */
double variance(const DynamicArray &dynamic_array);

/**
 * @brief Computes the stddev.
 *
 * @param dynamic_array
 * @return double
 */
double stddev(DynamicArray &dynamic_array);
