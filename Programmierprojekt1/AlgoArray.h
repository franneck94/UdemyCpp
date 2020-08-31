#pragma once

#include "DynArray.h"

/**
 * @brief Compute the Mean Value of a given Array.
 * 
 * @param dynamic_array 
 * @return double 
 */
double mean(DynamicArray &dynamic_array);

/**
 * @brief Compute the Sum Value over the given Array.
 * 
 * @param dynamic_array 
 * @return double 
 */
double sum(DynamicArray &dynamic_array);

/**
 * @brief Compute the median value over the array

 * 
 * @param dynamic_array 
 * @return double 
 */
double median(DynamicArray &dynamic_array);

/**
 * @brief Compute the variance value over the array

 * 
 * @param dynamic_array 
 * @return double 
 */
double variance(DynamicArray &dynamic_array);

/**
 * @brief Compute the stddev value over the array

 * 
 * @param dynamic_array 
 * @return double 
 */
double stddev(DynamicArray &dynamic_array);
