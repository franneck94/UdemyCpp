#include <cstdint>
#include <iostream>

#include "exercise.h"

int main()
{
    // Exercise 1
    std::uint32_t array_length = 100;
    double sum = 0.0;

    double *array1 = new double[array_length];

    for (std::uint32_t i = 0; i < 100; i++)
    {
        array1[i] = i;
    }

    sum = array_sum(array1, array_length);
    std::cout << "(Exercise 1) Array Sum = " << sum << std::endl;

    // Exercise 2
    std::uint32_t input_array_length = 0;
    int input_array_value = 0;

    std::cout << std::endl << "Enter the array length: " << std::endl;
    std::cin >> input_array_length;
    std::cout << std::endl << "Enter the array value: " << std::endl;
    std::cin >> input_array_value;
    std::cout << std::endl;

    int *array2 = array_constructor(input_array_value, input_array_length);

    for (std::uint32_t i = 0; i < input_array_length; i++)
    {
        std::cout << array2[i] << std::endl;
    }

    delete[] array2;

    return 0;
}
