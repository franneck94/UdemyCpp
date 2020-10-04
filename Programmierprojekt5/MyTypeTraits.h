#pragma once

#include <cstddef>
#include <type_traits>

#include "MyVector.h"
#include "MyArray.h"
#include "MyIterators.h"

namespace cpp
{

template <typename T>
struct is_container : public std::false_type {};

template<class T, class Alloc>
struct is_container<cpp::vector<T, Alloc>> : public std::true_type {};

template <typename T>
struct is_forward_iterator : public std::false_type {};

template<class T>
struct is_forward_iterator<cpp::RandomAcessIterator<T>> : public std::true_type {};

} // namespace cpp