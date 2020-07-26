#include "DynArray.h"
 
/**
Create a dynamic array with given length and constant value to fill in.

@param value: Constant value to fill in
@param length: Length of the array
@return: Dynmaic array
*/
double* create_dynamic_array(const double &value, const unsigned int &length)
{
	double* dynamic_array;
	dynamic_array = new double[length];

	for (int i = 0; i < length; i++)
	{
		dynamic_array[i] = value;
	}

	return dynamic_array;
}

/**
Append given Value at the end of the Dynamic Array

@param array: Input array
@param length: Current length of the array
@param array: Value to append
*/
void push_back(double* &dynamic_array, const unsigned int &length, const double &value)
{
	double *temp;
	temp = new double[length + 1];

	for (int i = 0; i < length; i++)
	{
		temp[i] = dynamic_array[i];
	}

	temp[length] = value;

	delete[] dynamic_array;

	dynamic_array = new double[length + 1];

	for (int i = 0; i < length + 1; i++)
	{
		dynamic_array[i] = temp[i];
	}

	delete[] temp;
}

/**
Delete last value in the dynamic array

@param array: Input array
@param length: Current length of the array
*/
void pop_back(double* &dynamic_array, const unsigned int &length)
{
	double *temp;
	temp = new double[length - 1];

	for (int i = 0; i < length - 1; i++)
	{
		temp[i] = dynamic_array[i];
	}

	delete[] dynamic_array;

	dynamic_array = new double[length - 1];

	for (int i = 0; i < length - 1; i++)
	{
		dynamic_array[i] = temp[i];
	}

	delete[] temp;
}