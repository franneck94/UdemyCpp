#pragma once

struct DynamicArray
{
	double* m_data;
	unsigned int m_length;
};

/**
Create a dynamic array with given length and constant value to fill in.

@param value: Constant value to fill in
@param length: Length of the array
@return: Dynmaic array
*/
DynamicArray create_dynamic_array(const double &value, const unsigned int &length);

/**
Append given Value at the end of the Dynamic Array

@param array: Input array
@param size: Current size of the array
@param array: Value to append
*/
void push_back(DynamicArray &dynamic_array, const double &value);

/**
Delete last value in the dynamic array

@param array: Input array
@param size: Current size of the array
*/
void pop_back(DynamicArray &dynamic_array);