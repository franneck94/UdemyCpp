#include "DynArray.h"

/**
Create a dynamic array with given length and constant value to fill in.
 
@param value: Constant value to fill in
@param length: Length of the array
@return: Dynmaic array
*/
DynamicArray create_dynamic_array(const double &value, const unsigned int &length)
{
	DynamicArray dynamic_array;
	dynamic_array.m_length = length;
	dynamic_array.m_data = new double[length];

	for (int i = 0; i < length; i++)
	{
		dynamic_array.m_data[i] = value;
	}

	return dynamic_array;
}

/**
Append given Value at the end of the Dynamic Array

@param array: Input array
@param dynamic_array.m_length: Current dynamic_array.m_length of the array
@param array: Value to append
*/
void push_back(DynamicArray &dynamic_array, const double &value)
{
	double *temp;
	temp = new double[dynamic_array.m_length + 1];

	for (int i = 0; i < dynamic_array.m_length; i++)
	{
		temp[i] = dynamic_array.m_data[i];
	}

	temp[dynamic_array.m_length] = value;

	delete[] dynamic_array.m_data;

	dynamic_array.m_data = new double[dynamic_array.m_length + 1];

	for (int i = 0; i < dynamic_array.m_length + 1; i++)
	{
		dynamic_array.m_data[i] = temp[i];
	}

	dynamic_array.m_length++;
	delete[] temp;
}

/**
Delete last value in the dynamic array

@param array: Input array
@param dynamic_array.m_length: Current dynamic_array.m_length of the array
*/
void pop_back(DynamicArray &dynamic_array)
{
	double *temp;
	temp = new double[dynamic_array.m_length - 1];

	for (int i = 0; i < dynamic_array.m_length - 1; i++)
	{
		temp[i] = dynamic_array.m_data[i];
	}

	delete[] dynamic_array.m_data;

	dynamic_array.m_data = new double[dynamic_array.m_length - 1];

	for (int i = 0; i < dynamic_array.m_length - 1; i++)
	{
		dynamic_array.m_data[i] = temp[i];
	}

	dynamic_array.m_length--;
	delete[] temp;
}