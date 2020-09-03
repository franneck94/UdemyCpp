#pragma once

// & := Lvalue Reference
// && := Rvalue Reference
// Rvalue: Temp. Speicher
// Move: Klaut den Speicher
template <typename T>
class DynamicArray
{
private:
	unsigned int m_length;

public:
	T *m_data;

	DynamicArray<T>();											 // Default constructor
	DynamicArray<T>(const T &value, const unsigned int &length); // User defined constructor
	~DynamicArray<T>();											 // User defined destructor

	DynamicArray<T>(const DynamicArray<T> &x); // Copy constructor
	//DynamicArray<T>& operator=(DynamicArray<T> x); // Copy assignment operator

	DynamicArray<T>(DynamicArray<T> &&x);			 // Move constructor
	DynamicArray<T> &operator=(DynamicArray<T> &&x); // Move assignment operator

	unsigned int get_length();

	void push_back(const T &value);
	void pop_back();

	T &operator[](const unsigned int &i);
};

//#include "DynArray.h"

/**
Create empty dynamic array.
*/
template <typename T>
DynamicArray<T>::DynamicArray() : m_data(nullptr), m_length(0)
{
}

/**
Create a dynamic array with given m_length and constant value to fill in.

@param value: Constant value to fill in
@param m_length: Length of the array
*/
template <typename T>
DynamicArray<T>::DynamicArray(const T &value, const unsigned int &m_length) : m_data(new T[m_length]), m_length(m_length)
{
	for (int i = 0; i != m_length; ++i)
	{
		m_data[i] = value;
	}
}

/**
Frees dynamic array.
*/
template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] m_data;
	m_data = nullptr;
}

// Copy constructor
template <typename T>
DynamicArray<T>::DynamicArray<T>(const DynamicArray<T> &x) : m_length(x.m_length), m_data(new T[m_length])
{
	for (int i = 0; i != m_length; ++i)
	{
		m_data[i] = x.m_data[i];
	}
}

// Copy assignment operator
//template<typename T>
//DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T> x)
//{
//	std::swap(m_length, x.m_length);
//	std::swap(m_data, x.m_data);
//
//	return *this;
//}

// Move constructor
template <typename T>
DynamicArray<T>::DynamicArray<T>(DynamicArray<T> &&x) : m_length(std::move(x.m_length)), m_data(std::move(x.m_data))
{
	x.m_length = 0;
	x.m_data = nullptr;
}

// Move assignment operator
template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(DynamicArray<T> &&x)
{
	delete[] m_data;

	m_length = std::move(x.m_length);
	m_data = std::move(x.m_data);

	x.m_length = 0;
	x.m_data = nullptr;

	return *this;
}

/**
Get the current m_length of the dynamic array.

@return uint: Dynamic array m_length.
*/
template <typename T>
unsigned int DynamicArray<T>::get_length()
{
	return m_length;
}

/**
Append given Value at the end of the Dynamic Array

@param array: Value to append
*/
template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
	T *temp;
	temp = new T[m_length + 1];

	for (int i = 0; i < m_length; i++)
	{
		temp[i] = m_data[i];
	}

	temp[m_length] = value;

	delete[] m_data;

	m_data = new T[m_length + 1];

	for (int i = 0; i < m_length + 1; i++)
	{
		m_data[i] = temp[i];
	}

	m_length++;
	delete[] temp;
}

/**
Delete last value in the dynamic array
*/
template <typename T>
void DynamicArray<T>::pop_back()
{
	T *temp;
	temp = new T[m_length - 1];

	for (int i = 0; i < m_length - 1; i++)
	{
		temp[i] = m_data[i];
	}

	delete[] m_data;

	m_data = new T[m_length - 1];

	for (int i = 0; i < m_length - 1; i++)
	{
		m_data[i] = temp[i];
	}

	m_length--;
	delete[] temp;
}

template <typename T>
T &DynamicArray<T>::operator[](const unsigned int &i)
{
	return m_data[i];
}