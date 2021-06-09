#include <iostream>

#include "exercise.h"

namespace computation
{
// Exercise 1
double mean_array_value(int *array, const unsigned int &length)
{
    double mean_value = 0.0;

    for (unsigned int i = 0; i < length; i++)
    {
        mean_value += array[i];
    }

    mean_value /= length;

    return mean_value;
}

double mean_array_value(double *array, const unsigned int &length)
{
    double mean_value = 0.0;

    for (unsigned int i = 0; i < length; i++)
    {
        mean_value += array[i];
    }

    mean_value /= length;

    return mean_value;
}
} // namespace computation
