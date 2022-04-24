#include <cmath>
#include <cstdlib>

#include "AlgoArray.h"
#include "DynArray.h"

double sum(const DynamicArray &dynamic_array)
{
    double sum_value = 0.0;

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
    double median_value = 0.0;

    const bool has_odd_length = static_cast<bool>(dynamic_array.m_length % 2);

    if (has_odd_length)
    {
        const std::size_t index = dynamic_array.m_length / 2;
        median_value = dynamic_array.m_data[index];
    }
    else
    {
        const std::size_t index1 = dynamic_array.m_length / 2;
        const std::size_t index2 = index1 - 1;
        median_value = (dynamic_array.m_data[index1] + dynamic_array.m_data[index2]) / 2.0;
    }

    return median_value;
}

double variance(const DynamicArray &dynamic_array)
{
    const double mean_value = mean(dynamic_array);
    const double probability = 1.0 / static_cast<double>(dynamic_array.m_length);

    double variance_value = 0.0;
    for (std::size_t i = 0; i < dynamic_array.m_length; i++)
    {
        variance_value += pow(dynamic_array.m_data[i] - mean_value, 2.0) * probability;
    }

    return variance_value;
}

double stddev(DynamicArray &dynamic_array)
{
    const double variance_value = variance(dynamic_array);
    const double stddev_value = sqrt(variance_value);

    return stddev_value;
}
