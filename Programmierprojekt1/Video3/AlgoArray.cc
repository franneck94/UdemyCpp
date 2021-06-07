#include <cstddef>

#include "AlgoArray.h"
#include "DynArray.h"


double sum(DynamicArray &dynamic_array)
{
    double sum_value = 0.0;

    for (std::size_t i = 0; i < dynamic_array.m_length; i++)
    {
        sum_value += dynamic_array.m_data[i];
    }

    return sum_value;
}

double mean(DynamicArray &dynamic_array)
{
    return sum(dynamic_array) / static_cast<double>(dynamic_array.m_length);
}

double median(DynamicArray &dynamic_array)
{
    double median_value = 0.0;
    bool has_odd_length = static_cast<bool>(dynamic_array.m_length % 2u);

    if (has_odd_length)
    {
        std::size_t index = dynamic_array.m_length / 2u;
        median_value = dynamic_array.m_data[index];
    }
    else
    {
        std::size_t index1 = dynamic_array.m_length / 2u;
        std::size_t index2 = index1 - 1u;
        median_value = (dynamic_array.m_data[index1] + dynamic_array.m_data[index2]) / 2.0;
    }

    return median_value;
}
