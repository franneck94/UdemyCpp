#pragma once

#include <cstddef>
#include <cstdint>

// Exercise 1
void push_back(std::int32_t *&input_array,
               const std::size_t size,
               const std::int32_t value);

// Exercise 2
void pop_back(std::int32_t *&input_array, const std::size_t size);
