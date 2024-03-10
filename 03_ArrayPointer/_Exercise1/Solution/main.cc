#include <cstdint>
#include <iostream>

#include "exercise.h"

int main()
{
    constexpr auto array_length = std::size_t{100};

    // Exercise 1
    double array1[array_length] = {};
    for (std::size_t i = 0; i < array_length; i++)
    {
        array1[i] = static_cast<double>(i);
    }

    // Exercise 2
    const auto sum = array_sum(array1, array_length);
    std::cout << "(Exercise 2) Array Sum = " << sum << '\n';

    // Exercise 3
    std::array<double, 100> array2;
    for (std::size_t i = 0; i < array_length; i++)
    {
        array2[i] = static_cast<double>(i);
    }

    const auto sum2 = array_sum(array2);
    std::cout << "(Exercise 3) Array Sum = " << sum2 << '\n';

    return 0;
}
