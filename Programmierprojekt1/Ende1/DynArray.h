#pragma once

/**
Create a dynamic array with given length and constant value to fill in.
 
@param value: Constant value to fill in
@param length: Length of the array
@return: Dynmaic array
*/
double* create_dynamic_array(const double &value, const unsigned int &length);

/**
Append given Value at the end of the Dynamic Array

@param array: Input array
@param size: Current size of the array
@param array: Value to append
*/
void push_back(double* &dynamic_array, const unsigned int &length, const double &value);

/**
Delete last value in the dynamic array

@param array: Input array
@param size: Current size of the array
*/
void pop_back(double* &dynamic_array, const unsigned int &length);