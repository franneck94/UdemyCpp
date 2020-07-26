//#include "DynArray.h"
//
///**
//Create empty dynamic array.
//*/
//template<typename T>
//DynamicArray<T>::DynamicArray() :
//	m_data(nullptr), m_length(0)
//{
//
//}
//
///**
//Create a dynamic array with given m_length and constant value to fill in.
//
//@param value: Constant value to fill in
//@param m_length: Length of the array
//*/
//template<typename T>
//DynamicArray<T>::DynamicArray(const double &value, const unsigned int &m_length):
//	m_data(new double[m_length]), m_length(m_length)
//{
//	for (int i = 0; i != m_length; ++i)
//	{
//		m_data[i] = value;
//	}
//}
//
///**
//Get the current m_length of the dynamic array.
//
//@return uint: Dynamic array m_length.
//*/
//template<typename T>
//unsigned int DynamicArray<T>::get_length()
//{
//	return m_length;
//}
//
///**
//Append given Value at the end of the Dynamic Array
//
//@param array: Value to append
//*/
//template<typename T>
//void DynamicArray<T>::push_back(const double &value)
//{
//	double *temp;
//	temp = new double[m_length + 1];
//
//	for (int i = 0; i < m_length; i++)
//	{
//		temp[i] = m_data[i];
//	}
//
//	temp[m_length] = value;
//
//	delete[] m_data;
//
//	m_data = new double[m_length + 1];
//
//	for (int i = 0; i < m_length + 1; i++)
//	{
//		m_data[i] = temp[i];
//	}
//
//	m_length++;
//	delete[] temp;
//}
//
///**
//Delete last value in the dynamic array
//*/
//template<typename T>
//void DynamicArray<T>::pop_back()
//{
//	double *temp;
//	temp = new double[m_length - 1];
//
//	for (int i = 0; i < m_length - 1; i++)
//	{
//		temp[i] = m_data[i];
//	}
//
//	delete[] m_data;
//
//	m_data = new double[m_length - 1];
//
//	for (int i = 0; i < m_length - 1; i++)
//	{
//		m_data[i] = temp[i];
//	}
//
//	m_length--;
//	delete[] temp;
//}
//
//template<typename T>
//double& DynamicArray<T>::operator[](const unsigned int &i)
//{
//	return m_data[i];
//}