#pragma once

#include <cstddef>

/**
 * @brief Push backs the *value* at the end of the array.
 *
 * @param input_array The input pointer to an integer array.
 * @param size The size of the array.
 * @param value The value to append to the array.
 */
void push_back(int *&input_array, const std::size_t &size, const int &value);

/**
 * @brief Pop backs the value at the end of the vector.
 *
 * @param input_array The input pointer to an integer array.
 * @param size The size of the array.
 */
void pop_back(int *&input_array, const std::size_t &size);
