#include <cstdint>
#include <iostream>

#include "exercise.h"

int main()
{
    // Exercise 1
    auto array_length = std::size_t{100};
    auto sum = 0.0;

    auto *array1 = new double[array_length];

    for (std::size_t i = 0; i < array_length; i++)
    {
        array1[i] = i;
    }

    sum = array_sum(array1, array_length);
    std::cout << "(Exercise 1) Array Sum = " << sum << '\n';
    delete[] array1;
    array1 = nullptr;

    // Exercise 2
    auto input_array_length = std::size_t{0};
    auto input_array_value = std::int32_t{0};

    std::cout << '\n' << "Enter the array length: " << '\n';
    std::cin >> input_array_length;
    std::cout << '\n' << "Enter the array value: " << '\n';
    std::cin >> input_array_value;
    std::cout << '\n';

    auto *array2 = array_constructor(input_array_value, input_array_length);

    for (std::size_t i = 0; i < input_array_length; i++)
    {
        std::cout << array2[i] << '\n';
    }

    delete[] array2;
    array2 = nullptr;

    return 0;
}
