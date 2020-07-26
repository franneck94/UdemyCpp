#pragma once
#include "DynArray.h"
 
/**
Compute the Mean Value of a given Array.

@param array: Input array
@param length: Length of the array
@return: Mean value
*/
double mean(DynamicArray &dynamic_array);

/**
Compute the Sum Value over the given Array

@param array: Input array
@param length: Length of the array
@return: Sum Value
*/
double sum(DynamicArray &dynamic_array);

/**
Compute the median value over the array

@param dynamic_array
@return: Median value
*/
double median(DynamicArray &dynamic_array);

/**
Compute the variance value over the array

@param dynamic_array
@return: Variance value
*/
double variance(DynamicArray &dynamic_array);

/**
Compute the stddev value over the array

@param dynamic_array
@return: Stddev value
*/
double stddev(DynamicArray &dynamic_array);