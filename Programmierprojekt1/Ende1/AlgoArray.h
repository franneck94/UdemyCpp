#pragma once
#include "DynArray.h"
 
/**
Compute the Mean Value of a given Array.

@param array: Input array
@param length: Length of the array
@return: Mean value
*/
double mean(double* &dynamic_array, const unsigned int &length);

/**
Compute the Sum Value over the given Array

@param array: Input array
@param length: Length of the array
@return: Sum Value
*/
double sum(double* &dynamic_array, const unsigned int &length);