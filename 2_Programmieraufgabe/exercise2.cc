#include <iostream>
#include "exercise2.h"

using std::cout;
using std::endl;
using std::cin;

// Aufgabe 1
void push_back(int*& input_array, const int& size, const int& value)
{
	int* temp;
	temp = new int[size + 1];
	
	for (int i = 0; i < size; i++)
	{
		temp[i] = input_array[i];
	}
	temp[size] = value;
	
	delete[] input_array;
	input_array = new int[size + 1];
 
	for (int i = 0; i < size + 1; i++)
	{
		input_array[i] = temp[i];
	}
	delete[] temp;
}

// Aufgabe 2
void pop_back(int *&input_array, const int &size)
{
	int *temp;
	temp = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = input_array[i];
	}

	delete[] input_array;

	input_array = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		input_array[i] = temp[i];
	}

	delete[] temp;
}