#pragma once

#include <math.h>

#include "MyTypeTraits.h"

namespace cppmath
{

template <class InputIterator>
auto sum(InputIterator itBegin, InputIterator itEnd)
{
    auto sum_value{ 0 };

    for (InputIterator it = itBegin; it != itEnd; ++it)
    {
        sum_value += *it;
    }

    return sum_value;
}

// template <class Container, std::enable_if<is_cpp_container<Container>::value>>
// double mean(Container &container)
// {
//     return sum(container) / container.size();
// }

// template <class Container, std::enable_if<is_cpp_container<Container>::value>>
// double median(Container &container)
// {
//     double median_value = 0.0;
//     bool has_odd_length = container.size() % 2;

//     if (has_odd_length)
//     {
//         std::size_t index = container.size() / 2;
//         median_value = container[index];
//     }
//     else
//     {
//         std::size_t index1 = container.size() / 2;
//         std::size_t index2 = index1 - 1;
//         median_value = (container[index1] + container[index2]) / 2.0;
//     }

//     return median_value;
// }

// template <class Container, std::enable_if<is_cpp_container<Container>::value>>
// double variance(Container &container)
// {
//     double mean_value = mean(container);
//     double variance_value = 0.0;
//     double probability = 1.0 / (double)container.size();

//     for (std::size_t i = 0; i < container.size(); ++i)
//     {
//         double x_i = container[i];
//         variance_value += pow(x_i - mean_value, 2.0) * probability;
//     }

//     return variance_value;
// }

// template <class Container, std::enable_if<is_cpp_container<Container>::value>>
// double stddev(Container &container)
// {
//     double variance_value = variance(container);
//     double stddev_value = sqrt(variance_value);

//     return stddev_value;
// }

} // end namespace