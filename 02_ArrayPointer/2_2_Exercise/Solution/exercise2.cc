#include <iostream>

#include "exercise2.h"

// Exercise 1
void push_back(int *&input_array, const unsigned int &size, const int &value)
{
    int *temp = new int[size + 1];

    for (unsigned int i = 0; i < size; i++)
    {
        temp[i] = input_array[i];
    }

    temp[size] = value;

    delete[] input_array;

    input_array = temp;
}

// Exercise 2
void pop_back(int *&input_array, const unsigned int &size)
{
    int *temp = new int[size - 1];

    for (int i = 0; i < size - 1; i++)
    {
        temp[i] = input_array[i];
    }

    delete[] input_array;

    input_array = temp;
}
