#include <cstdint>
#include <iostream>

#include "exercise.h"

int main()
{
    // Exercise 1
    constexpr auto array_length = std::size_t{100};
    double array1[array_length] = {};

    for (std::size_t i = 0; i < array_length; i++)
    {
        array1[i] = i;
    }

    // Exercise 2
    auto sum = 0.0;

    const auto sum = array_sum(array1, array_length);
    std::cout << "(Exercise 2) Array Sum = " << sum << '\n';

    // Exercise 3
    std::array<double, 100> array2;
    auto sum2 = 0.0;

    const auto sum2 = array_sum(array2);
    std::cout << "(Exercise 2) Array Sum = " << sum << '\n';

    return 0;
}
