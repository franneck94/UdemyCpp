#include "exercise.h"
#include <iostream>


int main()
{
    // Exercise 1
    const unsigned int array_length = 100;
    double sum = 0.0;

    double *p_array_exercise1 = nullptr;
    p_array_exercise1 = new double[array_length];

    for (unsigned int i = 0; i < 100; i++)
    {
        p_array_exercise1[i] = i;
    }

    sum = array_sum(p_array_exercise1, array_length);
    std::cout << "(Exercise 1) Array Sum = " << sum << std::endl;

    // Exercise 2
    unsigned int input_array_length = 0;
    int input_array_value = 0;

    std::cout << std::endl << "Gebe Array Length ein!" << std::endl;
    std::cin >> input_array_length;
    std::cout << std::endl << "Gebe Array Wert ein!" << std::endl;
    std::cin >> input_array_value;

    int *p_array_exercise2 =
        array_constructor(input_array_value, input_array_length);

    for (unsigned int i = 0; i < input_array_length; i++)
    {
        std::cout << p_array_exercise2[i] << std::endl;
    }

    return 0;
}
