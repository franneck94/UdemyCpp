#include "AlgoArray.h"
#include "DynArray.h"

/**
Compute the Mean Value of a given Array.

@param array: Input array
@param length: Length of the array
@return: Mean value
*/
double mean(DynamicArray &dynamic_array)
{
	double mean_value = 0.0;

	for (int i = 0; i < dynamic_array.m_length; i++)
	{
		mean_value += dynamic_array.m_data[i];
	}

	mean_value /= dynamic_array.m_length;

	return mean_value;
}

/**
Compute the Sum Value over the given Array

@param array: Input array
@param length: Length of the array
@return: Sum value
*/
double sum(DynamicArray &dynamic_array)
{
	double sum_value = 0.0;

	for (int i = 0; i < dynamic_array.m_length; i++)
	{
		sum_value += dynamic_array.m_data[i];
	}

	return sum_value;
}