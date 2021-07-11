#include <cstddef>
#include <iostream>

#include "DynArray.h"

// int main()
int main()
{
    double fill_value = 1.0;
    std::size_t length = 4;

    DynamicArray my_array = create_dynamic_array(fill_value, length);

    for (std::size_t i = 0; i < length; i++)
    {
        std::cout << my_array.m_data[i] << std::endl;
    }

    return 0;
}
