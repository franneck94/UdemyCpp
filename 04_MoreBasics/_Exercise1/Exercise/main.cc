#include <array>
#include <cstdint>
#include <iostream>

#include "exercise.h"

int main()
{
    // Exercise 1
    const auto array_elements = 5;
    std::array<int, array_elements> array_a = {1, 2, 3, 4, 5};
    std::array<double, array_elements> array_b = {1.0, 2.5, 3.5, 4.5, 10.0};

    const auto mean_array_a = computation::mean_array_value(array_a);
    const auto mean_array_b = computation::mean_array_value(array_b);

    std::cout << "Mean Array A: " << mean_array_a << '\n';
    std::cout << "Mean Array B: " << mean_array_b << '\n';

    // Exercise 2
    computation::Dataset data{mean_array_a, mean_array_b};
    std::cout << data.mean_array_a << '\n';
    std::cout << data.mean_array_b << '\n';

    return 0;
}
