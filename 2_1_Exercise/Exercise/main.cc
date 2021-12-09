#include <iostream>

#include "exercise.h"

int main()
{
    // Exercise 1
    const unsigned int array_length = 100;
    double sum = 0.0;

    double *p_array1 = nullptr;
    p_array1 = new double[array_length];

    for (unsigned int i = 0; i < 100; i++)
    {
        p_array1[i] = i;
    }

    sum = array_sum(p_array1, array_length);
    std::cout << "(Exercise 1) Array Sum = " << sum << std::endl;

    // Exercise 2
    unsigned int input_array_length = 0;
    int input_array_value = 0;

    std::cout << std::endl << "Enter the array length: " << std::endl;
    std::cin >> input_array_length;
    std::cout << std::endl << "Enter the array value: " << std::endl;
    std::cin >> input_array_value;

    int *p_array2 = array_constructor(input_array_value, input_array_length);

    for (unsigned int i = 0; i < input_array_length; i++)
    {
        std::cout << p_array2[i] << std::endl;
    }

    return 0;
}
