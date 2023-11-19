#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

std::int32_t gen()
{
    static auto seed = std::random_device{};
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    return dist(gen);
}

int main()
{
    auto my_vector = std::vector<int>(10, 0);
    std::generate(my_vector.begin(), my_vector.end(), gen);

    auto my_result = std::vector<int>(10, 0);

    for (const auto &val : my_vector)
    {
        std::cout << val << '\n';
    }
    std::cout << '\n';

    // Exercise 1
    const auto has_no_even =
        std::none_of(my_vector.begin(), my_vector.end(), ...);

    if (has_no_even)
    {
        std::cout << "None of the vector values are even" << '\n';
    }
    else
    {
        std::cout << "The vector has even numbers" << '\n';
    }

    // Exercise 2
    std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), ...);

    for (const auto &val : my_result)
    {
        std::cout << val << '\n';
    }

    return 0;
}
