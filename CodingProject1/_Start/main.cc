#include <cstdlib>
#include <iostream>

#include "AlgoArray.h"
#include "DynArray.h"

int main()
{
    auto fill_value = 1.0;
    auto length = std::size_t{5};

    auto my_array = create_dynamic_array(fill_value, length);

    for (std::size_t i = 0; i < length; i++)
    {
        my_array.m_data[i] = static_cast<double>(i);
    }

    std::cout << "Mean = " << mean(my_array) << '\n';
    std::cout << "Median = " << median(my_array) << '\n';

    return 0;
}
