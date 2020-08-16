#include <iostream>
#include "exercise.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	// Aufgabe 1
	const unsigned int array_elements = 5;
	int array_a[array_elements] = { 1, 2, 3, 4, 5 };
	double array_b[array_elements] = { 1.0, 2.5, 3.5, 4.5, 10.0 };

	double mean_array_a = computation::mean_array_value(array_a, array_elements);
	double mean_array_b = computation::mean_array_value(array_b, array_elements);

	cout << "Mean Array A: " << mean_array_a << endl;
	cout << "Mean Array B: " << mean_array_b << endl;

	// Aufgabe 2
	computation::Dataset data{ mean_array_a, mean_array_b };

	return 0;
}