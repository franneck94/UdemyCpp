#include <cstdlib>
#include <iostream>

#include "DynArray.h"

DynamicArray create_dynamic_array(const double value, const std::size_t length)
{
    auto dynamic_array = DynamicArray{nullptr, 0};

    dynamic_array.m_length = length;
    dynamic_array.m_data = new double[length];

    for (std::size_t i = 0; i < length; i++)
    {
        dynamic_array.m_data[i] = value;
    }

    return dynamic_array;
}

void push_back(DynamicArray &dynmaic_array, const int &value)
{
    auto *temp = new double[dynmaic_array.m_length + 1];

    for (std::size_t i = 0; i < dynmaic_array.m_length; i++)
    {
        temp[i] = dynmaic_array.m_data[i];
    }

    temp[dynmaic_array.m_length] = value;

    delete[] dynmaic_array.m_data;

    dynmaic_array.m_data = temp;
    dynmaic_array.m_length++;
}

void pop_back(DynamicArray &dynmaic_array)
{
    auto *temp = new double[dynmaic_array.m_length - 1];

    for (std::size_t i = 0; i < dynmaic_array.m_length - 1; i++)
    {
        temp[i] = dynmaic_array.m_data[i];
    }

    delete[] dynmaic_array.m_data;

    dynmaic_array.m_data = temp;
    dynmaic_array.m_length--;
}
