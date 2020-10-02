#pragma once

#include <cstddef>
#include <type_traits>

#include "MyVector.h"
#include "MyArray.h"
#include "MyIterators.h"

namespace cppmath
{

template <typename T>
struct is_container : public std::false_type {};

template<class T, class Alloc>
struct is_container<cppmath::Vector<T, Alloc>> : public std::true_type {};

template <typename T>
struct is_forward_iterator : public std::false_type {};

template<class T>
struct is_forward_iterator<cppmath::RandomAcessIterator<T>> : public std::true_type {};

} // namespace cppmath