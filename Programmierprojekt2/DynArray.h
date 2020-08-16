#pragma once

template<typename T>
class DynamicArray
{
private:
	T *m_data;
	unsigned int m_length;
	unsigned int m_capacity;

public:
	DynamicArray<T>();
	DynamicArray<T>(const T &value, const unsigned int &length);

	unsigned int get_length();
	unsigned int get_capacity();

	void push_back(const T &value);
	void pop_back();

	T& operator[](const unsigned int &i);
};

//#include "DynArray.h"

/**
Create empty dynamic array.
*/
template<typename T>
DynamicArray<T>::DynamicArray() :
	m_data(nullptr), m_length(0), m_capacity(0)
{

}

/**
Create a dynamic array with given m_length and constant value to fill in.

@param value: Constant value to fill in
@param m_length: Length of the array
*/
template<typename T>
DynamicArray<T>::DynamicArray(const T &value, const unsigned int &length) :
	m_data(new T[m_capacity]), m_length(length), m_capacity(length)
{
	std::cout << m_data << std::endl;

	for (int i = 0; i < m_length; ++i)
	{
		m_data[i] = value;
	}
}

/**
Get the current m_length of the dynamic array.

@return uint: Dynamic array m_length.
*/
template<typename T>
unsigned int DynamicArray<T>::get_length()
{
	return m_length;
}

/**
Get the current m_length of the dynamic array.

@return uint: Dynamic array m_length.
*/
template<typename T>
unsigned int DynamicArray<T>::get_capacity()
{
	return m_capacity;
}

/**
Append given Value at the end of the Dynamic Array

@param array: Value to append
*/
template<typename T>
void DynamicArray<T>::push_back(const T &value)
{
	if (m_length == m_capacity)
	{
		m_capacity *= 2;

		T *temp;
		temp = new T[m_capacity];

		for (int i = 0; i < m_length; i++)
		{
			temp[i] = m_data[i];
		}

		delete[] m_data;
		m_data = temp;
	}

	m_data[m_length] = value;
	m_length++;
}

/**
Delete last value in the dynamic array
*/
template<typename T>
void DynamicArray<T>::pop_back()
{
	if (m_length > 0)
	{
		m_length--;

		if (m_length < (m_capacity / 2))
		{
			m_capacity /= 2;

			T *temp;
			temp = new T[m_capacity];

			for (int i = 0; i < m_length; i++)
			{
				temp[i] = m_data[i];
			}

			delete[] m_data;
			m_data = temp;
		}
	}
}

template<typename T>
T& DynamicArray<T>::operator[](const unsigned int &i)
{
	return m_data[i];
}