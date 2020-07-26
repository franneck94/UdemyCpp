#include "AlgoArray.h"
#include "DynArray.h"
 
/**
Compute the Mean Value of a given Array.

@param array: Input array
@param length: Length of the array
@return: Mean value
*/
double mean(double* &dynamic_array, const unsigned int &length)
{
	double mean_value = 0.0;

	for (int i = 0; i < length; i++)
	{
		mean_value += dynamic_array[i];
	}

	mean_value /= length;

	return mean_value;
}

/**
Compute the Sum Value over the given Array

@param array: Input array
@param length: Length of the array
@return: Sum value
*/
double sum(double* &dynamic_array, const unsigned int &length)
{
	double sum_value = 0.0;

	for (int i = 0; i < length; i++)
	{
		sum_value += dynamic_array[i];
	}

	return sum_value;
}