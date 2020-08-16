#include <iostream>
#include <string>
#include "DynArray.h"
#include "AlgoArray.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	DynamicArray a(1, 4);

	for (int i = 0; i != a.get_length(); i++)
		a[i] = i+1;
	// 1, 2, 3, 4
	// Sum: 10
	// Mean: 2,5
	// Median: 2,5
	// Variance: 5
	// Stddev: sqrt(5)

	double sum_value = sum(a);
	double mean_value = mean(a);
	double median_value = median(a);
	double var_value = variance(a);
	double stddev_value = stddev(a);

	cout << endl << "Sum: " << sum_value;
	cout << endl << "Mean: " << mean_value;
	cout << endl << "Median: " << median_value;
	cout << endl << "Var: " << var_value;
	cout << endl << "Stddev: " << stddev_value;

	return 0;
}