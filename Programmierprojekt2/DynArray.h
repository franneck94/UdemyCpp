#pragma once

#include <cstddef>

/**
 * @brief DynamicArray class.
 * 
 * @tparam T 
 */
template <typename T>
class DynamicArray
{
private:
	std::size_t m_length;
	std::size_t m_capacity;
	T* m_data;

public:
	DynamicArray<T>();
	DynamicArray<T>(const T &value, const std::size_t &length);

	std::size_t get_length();
	std::size_t get_capacity();

	void push_back(const T &value);
	void pop_back();

	T &operator[](const std::size_t &i);
};

/**
 * @brief Construct a new Dynamic Array< T>:: Dynamic Array object
 * 
 * @tparam T 
 */
template <typename T>
DynamicArray<T>::DynamicArray(): 
	m_length(0), 
	m_capacity(0),
	m_data(nullptr)
{
}

/**
 * @brief Construct a new Dynamic Array< T>:: Dynamic Array object
 * 
 * @tparam T 
 * @param value 
 * @param length 
 */
template <typename T>
DynamicArray<T>::DynamicArray(const T &value, const std::size_t &length): 
	m_length(length), 
	m_capacity(length),
	m_data(nullptr)
{
	m_data = new T[m_capacity];

	for (std::size_t i = 0; i < m_length; ++i)
	{
		m_data[i] = value;
	}
}

/**
 * @brief Get the length of the dynamic array.
 * 
 * @tparam T 
 * @return std::size_t 
 */
template <typename T>
std::size_t DynamicArray<T>::get_length()
{
	return m_length;
}

/**
 * @brief Get the length of the capacity array.
 * 
 * @tparam T 
 * @return std::size_t 
 */
template <typename T>
std::size_t DynamicArray<T>::get_capacity()
{
	return m_capacity;
}

/**
 * @brief Push back the value at the end of the dynamic array.
 * 
 * @tparam T 
 * @param value 
 */
template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
	if (m_length == m_capacity)
	{
		m_capacity *= 2;

		T* temp = nullptr;
		temp = new T[m_capacity];

		for (std::size_t i = 0; i < m_length; i++)
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
 * @brief Pop back the value at the end of the dynamic array.
 * 
 * @tparam T 
 */
template <typename T>
void DynamicArray<T>::pop_back()
{
	if (m_length > 0)
	{
		m_length--;

		if (m_length < (m_capacity / 2))
		{
			m_capacity /= 2;

			T* temp = nullptr;
			temp = new T[m_capacity];

			for (std::size_t i = 0; i < m_length; i++)
			{
				temp[i] = m_data[i];
			}

			delete[] m_data;
			m_data = temp;
		}
	}
}

/**
 * @brief Get the i-th element of the dynamic array.
 * 
 * @tparam T 
 * @param i 
 * @return T& 
 */
template <typename T>
T& DynamicArray<T>::operator[](const std::size_t &i)
{
	return m_data[i];
}
