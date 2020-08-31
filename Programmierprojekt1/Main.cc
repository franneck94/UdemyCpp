#include <iostream>
#include <cstddef>

#include "DynArray.h"
#include "AlgoArray.h"

int main()
{
	DynamicArray a = create_dynamic_array(0, 4);

	for (std::size_t i = 0; i != a.m_length; ++i)
	{
		a.m_data[i] = i + 1;
	}

	double mean_a = mean(a);
	double sum_a = sum(a);
	double median_a = median(a);
	double var_a = variance(a);
	double stddev_a = stddev(a);

	std::cout << "Sum: " << sum_a << std::endl;
	std::cout << "Mean: " << mean_a << std::endl;
	std::cout << "Median: " << median_a << std::endl;
	std::cout << "Var: " << var_a << std::endl;
	std::cout << "Stddev: " << stddev_a << std::endl;

	return 0;
}
