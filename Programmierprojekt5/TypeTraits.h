#pragma once

#include <cstddef>
#include <type_traits>

#include "Vector.h"
#include "Array.h"
#include "Iterators.h"

namespace learncpp
{

template <typename T>
struct is_container : public std::false_type {};

template<class T, class Alloc>
struct is_container<learncpp::vector<T, Alloc>> : public std::true_type {};

template <typename T>
struct is_forward_iterator : public std::false_type {};

template<class T>
struct is_forward_iterator<learncpp::RandomAcessIterator<T>> : public std::true_type {};

} // namespace learncpp