#include <cassert>
#include <cstddef>
#include <iostream>

#include "AlgoArray.h"
#include "DynArray.h"

void test_cases();

int main()
{
    const double fill_value = 1.0;
    const std::size_t length = 0;

    DynamicArray<double> my_array(fill_value, length);

    my_array.push_back(0);
    my_array.push_back(1);
    my_array.push_back(2);
    my_array.push_back(3);
    my_array.push_back(4);

    for (std::size_t i = 0; i < my_array.get_length(); ++i)
    {
        std::cout << my_array[i] << '\n';
    }
    std::cout << '\n';

    // my_array.pop_back();
    // my_array.pop_back();

    for (std::size_t i = 0; i < my_array.get_length(); ++i)
    {
        std::cout << my_array[i] << '\n';
    }

    std::cout << "Mean = " << mean(my_array) << '\n';
    std::cout << "Median = " << median(my_array) << '\n';

    test_cases();

    return 0;
}

void test_cases()
{
    const std::size_t length = 2;
    DynamicArray<double> my_array(2.0, length);

    assert(my_array[0] == 2.0);
    assert(my_array[1] == 2.0);
    assert(my_array.get_length() == 2);

    my_array.push_back(0);
    my_array.push_back(1);

    assert(my_array[0] == 2.0);
    assert(my_array[1] == 2.0);
    assert(my_array[2] == 0.0);
    assert(my_array[3] == 1.0);
    assert(my_array.get_length() == 4);
}
