#include "AlgoArray.h"
#include "DynArray.h"
#include <math.h>

/**
Compute the Mean Value of a given Array.

@param array: Input array
@param length: Length of the array
@return: Mean value
*/
double mean(DynamicArray &dynamic_array)
{
	double mean_value = 0.0;
	unsigned int length = dynamic_array.get_length();

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
double sum(DynamicArray &dynamic_array)
{
	double sum_value = 0.0;
	unsigned int length = dynamic_array.get_length();

	for (int i = 0; i < length; i++)
	{
		sum_value += dynamic_array[i];
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
	bool is_odd = dynamic_array.get_length() % 2;
	double median_value = 0.0;

	if (is_odd)
	{
		// floor  = abrunden, ceil = aufrunden
		int index = floor(dynamic_array.get_length() / 2);
		median_value = dynamic_array[index];
	}
	else
	{
		int index1 = dynamic_array.get_length() / 2;
		int index2 = dynamic_array.get_length() / 2 - 1;
		median_value = 
			(dynamic_array[index1] + dynamic_array[index2]) / 2.0;
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
	double mean_value = mean(dynamic_array);
	double variance_value = 0.0;

	for (int i = 0; i != dynamic_array.get_length(); i++)
	{
		double a = dynamic_array[i];
		variance_value += pow(a - mean_value, 2.0);
	}

	return variance_value;
}

/**
Compute the stddev value over the array

@param dynamic_array
@return: Stddev value
*/
double stddev(DynamicArray &dynamic_array)
{
	double variance_value = variance(dynamic_array);
	double stddev_value = sqrt(variance_value);
	return stddev_value;
}