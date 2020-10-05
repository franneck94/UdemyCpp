#pragma once

#include <math.h>
#include <numeric>

#include "Vector.h"

namespace learncpp
{

template <class T>
T sum(learncpp::vector<T> &vec)
{
    return std::accumulate(vec.begin(), vec.end(), T());
}

template <class T>
T mean(learncpp::vector<T> &vec)
{
    return sum(vec) / vec.size();
}

template <class T>
T median(learncpp::vector<T> &vec)
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
T variance(learncpp::vector<T> &vec)
{
    T mean_value = mean(vec);
    T variance_value = 0.0;
    T probability = 1.0 / (double)vec.size();

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        T x_i = vec[i];
        variance_value += pow(x_i - mean_value, 2.0) * probability;
    }

    return variance_value;
}

template <class T>
T stddev(learncpp::vector<T> &vec)
{
    T variance_value = variance(vec);
    T stddev_value = sqrt(variance_value);

    return stddev_value;
}

} // end namespace