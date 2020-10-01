#include <type_traits>
#include <cstddef>

#include "MyVector.h"
#include "MyArray.h"

namespace cppmath
{

template <typename T>
struct is_cpp_container : public std::false_type {};

template<class T, class Alloc>
struct is_cpp_container<cppmath::Vector<T, Alloc>> : public std::true_type {};

template<class T, std::size_t N>
struct is_cpp_container<cppmath::Array<T, N>> : public std::true_type {};

} // namespace cppmath