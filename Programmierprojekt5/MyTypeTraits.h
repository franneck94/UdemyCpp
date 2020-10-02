#include <type_traits>
#include <cstddef>

#include "MyVector.h"
#include "MyArray.h"
#include "MyIterators.h"

namespace cppmath
{

template <typename T>
struct is_container : public std::false_type {};

template<class T, class Alloc>
struct is_container<cppmath::Vector<T, Alloc>> : public std::true_type {};

template<class T, std::size_t N>
struct is_container<cppmath::Array<T, N>> : public std::true_type {};

template <typename T>
struct is_iterator : public std::false_type {};

template<class T>
struct is_iterator<cppmath::RandomAcessIterator<T>> : public std::true_type {};

template<class T>
struct is_iterator<cppmath::ReverseRandomAcessIterator<T>> : public std::true_type {};

} // namespace cppmath