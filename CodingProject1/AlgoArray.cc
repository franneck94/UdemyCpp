#include <cmath>
#include <cstdlib>

#include "AlgoArray.h"
#include "DynArray.h"

double sum(const DynamicArray &dynamic_array)
{
    auto sum_value = 0.0;

    for (std::size_t i = 0; i < dynamic_array.m_length; i++)
    {
        sum_value += dynamic_array.m_data[i];
    }

    return sum_value;
}

double mean(const DynamicArray &dynamic_array)
{
    return sum(dynamic_array) / static_cast<double>(dynamic_array.m_length);
}

double median(const DynamicArray &dynamic_array)
{
    const auto has_even_length = dynamic_array.m_length % 2 == 0;

    if (has_even_length)
    {
        const auto index1 = dynamic_array.m_length / 2;
        const auto index2 = (dynamic_array.m_length / 2) - 1;
        return (dynamic_array.m_data[index1] + dynamic_array.m_data[index2]) /
               2.0;
    }

    const auto index = dynamic_array.m_length / 2;
    return dynamic_array.m_data[index];
}
