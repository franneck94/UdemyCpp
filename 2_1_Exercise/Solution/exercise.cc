#include <iostream>

#include "exercise.h"

// Exercise 1
double array_sum(const double *p_array, const unsigned int &length)
{
    double sum = 0.0;

    for (unsigned int i = 0; i < length; i++)
    {
        sum += p_array[i];
    }

    return sum;
}

// Exercise 2
int *array_constructor(const int &value, const unsigned int &length)
{
    int *constructed_array = new int[length];

    for (unsigned int i = 0; i < length; i++)
    {
        constructed_array[i] = value;
    }

    return constructed_array;
}
