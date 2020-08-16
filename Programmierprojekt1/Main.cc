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
	DynamicArray a = create_dynamic_array(0, 4);

	for (int i = 0; i != a.m_length; i++)
		a.m_data[i] = i+1;
	// 1, 2, 3, 4
	// Sum: 10
	// Mean: 2,5
	// Median: 2,5
	// Var: 5
	// Stddev: sqrt(5)

	double mean_a = mean(a);
	double sum_a = sum(a);
	double median_a = median(a);
	double var_a = variance(a);
	double stddev_a = stddev(a);

	cout << endl << "Sum: " << sum_a;
	cout << endl << "Mean: " << mean_a;
	cout << endl << "Median: " << median_a;
	cout << endl << "Var: " << var_a;
	cout << endl << "Stddev: " << stddev_a;

	/*for (int i = 0; i != a.m_length; i++)
		cout << endl << a.m_data[i];
	cout << endl << "Mean: " << mean_a;
	cout << endl << "Sum: " << sum_a << endl;

	push_back(a, 1337);
	for (int i = 0; i != a.m_length; i++)
		cout << endl << a.m_data[i];
	cout << endl;

	pop_back(a);
	for (int i = 0; i != a.m_length; i++)
		cout << endl << a.m_data[i];
	cout << endl;*/

	return 0;
}