#include <iostream>
#include "exercise.h"

int main()
{
	// Aufgabe 1
	const unsigned int array_length = 100;
	double sum;

	double *p_array_exercise1;
	p_array_exercise1 = new double[array_length];

	for (int i = 0; i < 100; i++)
	{
		p_array_exercise1[i] = i;
	}

	sum = array_sum(p_array_exercise1, array_length);
	std::cout << "(Exercise 1) Array Sum = " << sum << std::endl;

	// Aufgabe 2
	unsigned int input_array_length;
	int input_array_value;

	std::cout << std::endl
			  << "Gebe Array Length ein!" << std::endl;
	std::cin >> input_array_length;
	std::cout << std::endl
			  << "Gebe Array Wert ein!" << std::endl;
	std::cin >> input_array_value;

	int *p_array_exercise2 = array_constructor(input_array_value, input_array_length);

	for (int i = 0; i < input_array_length; i++)
	{
		std::cout << p_array_exercise2[i] << std::endl;
	}

	return 0;
}