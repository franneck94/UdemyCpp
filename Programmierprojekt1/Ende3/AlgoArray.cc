#include "AlgoArray.h"
#include "DynArray.h"
#include <math.h>
#include <iostream>
 
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

/**
Compute the median value over the array

@param dynamic_array
@return: Median value
*/
double median(DynamicArray &dynamic_array)
{
	// 1 3 5 7 8 9
	// Mean: 33 / 6
	// Median: 6

	bool is_odd = dynamic_array.m_length % 2;
	double median_value;

	if (is_odd)
	{
		int index = floor(dynamic_array.m_length / 2);
		median_value = dynamic_array.m_data[index];
	}
	// 1 2 3 4 5 6
	// l = 6
	// l / 2 = 3
	// l / 2 - 1 = 2
	else
	{
		int index1 = dynamic_array.m_length / 2;
		int index2 = dynamic_array.m_length / 2 - 1;
		median_value = (dynamic_array.m_data[index1] + dynamic_array.m_data[index2]) / 2;
	}

	return median_value;
}

/**
Compute the variance value over the array

@param dynamic_array
@return: Variance value
*/
double variance(DynamicArray &dynamic_array)
{
	// 1, 2, 3, 4
	// E(X) = (10) / 4 = 2.5
	// V(X) = [(1-2.5)^2 + (2-2.5)^2 + (3-2.5)^2 + (4-2.5)^2 ] / 4
	// V(X) = [2.25 + 0.25 + 0.25 + 2.25] / 4
	// V(X) = 5 / 4 = 1.25

	double variance_value = 0.0;
	double mean_value = mean(dynamic_array);

	for (int i = 0; i < dynamic_array.m_length; ++i)
	{
		variance_value += pow((dynamic_array.m_data[i] - mean_value), 2.0);
	}

	variance_value /= dynamic_array.m_length;
	return variance_value;
}

/**
Compute the stddev value over the array

@param dynamic_array
@return: Stddev value
*/
double stddev(DynamicArray &dynamic_array)
{
	double stddev_value = sqrt(variance(dynamic_array));
	return stddev_value;
}