//#include "AlgoArray.h"
#include "DynArray.h"
#include <math.h>


template<typename T>
double mean(DynamicArray<T> &dynamic_array)
{
	double mean_value = 0.0;

	for (std::size_t i = 0; i < dynamic_array.get_length(); i++)
	{
		mean_value += dynamic_array[i];
	}

	mean_value /= dynamic_array.get_length();

	return mean_value;
}


template<typename T>
double sum(DynamicArray<T> &dynamic_array)
{
	double sum_value = 0.0;

	for (std::size_t i = 0; i < dynamic_array.get_length(); i++)
	{
		sum_value += dynamic_array[i];
	}

	return sum_value;
}


template<typename T>
double median(DynamicArray<T> &dynamic_array)
{
	bool is_odd = dynamic_array.get_length() % 2;
	double median_value;

	if (is_odd)
	{
		std::size_t index = floor(dynamic_array.get_length() / 2);
		median_value = dynamic_array[index];
	}
	else
	{
		std::size_t index1 = dynamic_array.get_length() / 2;
		std::size_t index2 = dynamic_array.get_length() / 2 - 1;
		median_value = (dynamic_array[index1] + dynamic_array[index2]) / 2;
	}

	return median_value;
}


template<typename T>
double variance(DynamicArray<T> &dynamic_array)
{
	double mean_value = mean(dynamic_array);
	double variance_value = 0.0;

	for (std::size_t i = 0; i != dynamic_array.get_length(); i++)
	{
		double a = dynamic_array[i];
		variance_value += pow(a - mean_value, 2.0);
	}

	return variance_value;
}


template<typename T>
double stddev(DynamicArray<T> &dynamic_array)
{
	double stddev_value = variance(dynamic_array);
	stddev_value = sqrt(stddev_value);
	return stddev_value;
}