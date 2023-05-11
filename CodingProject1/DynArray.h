#pragma once

#include <cstdlib>

struct DynamicArray
{
    double *m_data;
    std::size_t m_length;
};

DynamicArray create_dynamic_array(const double value, const std::size_t length);

void push_back(DynamicArray &dynmaic_array, const double value);

void pop_back(DynamicArray &dynmaic_array);
