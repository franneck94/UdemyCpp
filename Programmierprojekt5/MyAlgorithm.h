#pragma once

#include <math.h>
#include <numeric>

#include "MyTypeTraits.h"

namespace cppmath
{

template <class T>
T sum(cppmath::Vector<T> &vec)
{
    return std::accumulate(vec.begin(), vec.end(), T());
}

template <class T>
auto mean(cppmath::Vector<T> &vec)
{
    return sum(vec) / vec.size();
}

template <class T>
auto median(cppmath::Vector<T> &vec)
{
    double median_value = 0.0;
    bool has_odd_length = vec.size() % 2;

    if (has_odd_length)
    {
        std::size_t index = vec.size() / 2;
        median_value = vec[index];
    }
    else
    {
        std::size_t index1 = vec.size() / 2;
        std::size_t index2 = index1 - 1;
        median_value = (vec[index1] + vec[index2]) / 2.0;
    }

    return median_value;
}

template <class T>
auto variance(cppmath::Vector<T> &vec)
{
    auto mean_value = mean(vec);
    auto variance_value = 0.0;
    auto probability = 1.0 / (double)vec.size();

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        auto x_i = vec[i];
        variance_value += pow(x_i - mean_value, 2.0) * probability;
    }

    return variance_value;
}

template <class T>
auto stddev(cppmath::Vector<T> &vec)
{
    auto variance_value = variance(vec);
    auto stddev_value = sqrt(variance_value);

    return stddev_value;
}

} // end namespace