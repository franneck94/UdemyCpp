#pragma once

#include <cstddef>

/**
 * @brief DynamicArray struct
 * 
 * @param double* m_data
 * @param std::size_t m_length
 */
struct DynamicArray
{
	double* m_data;
	std::size_t m_length;
};

/**
 * @brief Create a dynamic array object
 * 
 * @param value 
 * @param length 
 * @return DynamicArray 
 */
DynamicArray create_dynamic_array(const double &value, const std::size_t &length);

/**
 * @brief Append given Value at the end of the Dynamic Array
 * 
 * @param dynamic_array 
 * @param value 
 */
void push_back(DynamicArray &dynamic_array, const double &value);

/**
 * @brief Delete last value in the dynamic array
 * 
 * @param dynamic_array 
 */
void pop_back(DynamicArray &dynamic_array);
