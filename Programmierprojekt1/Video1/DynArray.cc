#include <iostream>

#include "DynArray.h"

void push_back(int *&input_array, const std::size_t &size, const int &value)
{
    int *temp = nullptr;
    temp = new int[size + 1];

    for (std::size_t i = 0; i < size; i++)
    {
        temp[i] = input_array[i];
    }

    temp[size] = value;

    delete[] input_array;

    input_array = temp;
}

void pop_back(int *&input_array, const std::size_t &size)
{
    int *temp = nullptr;
    temp = new int[size - 1];

    for (std::size_t i = 0; i < size - 1; i++)
    {
        temp[i] = input_array[i];
    }

    delete[] input_array;

    input_array = temp;
}
