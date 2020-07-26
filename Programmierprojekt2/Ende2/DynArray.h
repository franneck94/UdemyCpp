#pragma once

class DynamicArray
{
private:
	double* m_data;
	unsigned int m_length;
public:
	/**
	Create empty dynamic array.
	*/
	DynamicArray();

	/**
	Create a dynamic array with given length and constant value to fill in.

	@param value: Constant value to fill in
	@param length: Length of the array
	*/
	DynamicArray(const double &value, const unsigned int &length);

	/**
	Get the current length of the dynamic array.

	@return uint: Dynamic array length.
	*/
	unsigned int get_length();

	/**
	Get the current value of the dynamic array at index i.

	@param i: Array index
	@return double: Dynamic array length.
	*/
	double get_value(const unsigned int &i);

	/**
	Set the current value of the dynamic array at index i.

	@param i: Array index
	@param value: New array value
	*/
	void set_value(const unsigned int &i, const double &value);

	/**
	Append given Value at the end of the Dynamic Array

	@param array: Value to append
	*/
	void push_back(const double &value);

	/**
	Delete last value in the dynamic array
	*/
	void pop_back();
};