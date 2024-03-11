#include <cstdint>
#include <iostream>

#include "exercise.h"

// Exercise 1
void push_back(std::int32_t *&input_array,
               const std::size_t size,
               const std::int32_t value)
{
    auto *temp = new int[size + 1];

    for (std::size_t i = 0; i < size; i++)
    {
        temp[i] = input_array[i];
    }

    temp[size] = value;

    delete[] input_array;

    input_array = temp;
}

// Exercise 2
void pop_back(std::int32_t *&input_array, const std::size_t size)
{
    auto *temp = new int[size - 1];

    for (int i = 0; i < size - 1; i++)
    {
        temp[i] = input_array[i];
    }

    delete[] input_array;

    input_array = temp;
}
