#include <cstddef>
#include <iostream>
#include <vector>

#include "MyVector.h"
#include "MyArray.h"
#include "MyAlgorithm.h"
#include "MyIterators.h"
#include "MyTypeTraits.h"

int main()
{
    std::cout << "TESTING VECTOR" << std::endl;

    cppmath::Vector<double> a1(3, 1.0);
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;
    
    for (const auto& val : a1)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
    for (cppmath::Vector<double>::iterator it = a1.begin(); it != a1.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;
    for (cppmath::Vector<double>::const_iterator it = a1.cbegin(); it != a1.cend(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;
    for (cppmath::Vector<double>::reverse_iterator it = a1.rbegin(); it != a1.rend(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;
    for (cppmath::Vector<double>::const_reverse_iterator it = a1.crbegin(); it != a1.crend(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;
    std::cout << a1.empty() << std::endl;
    std::cout << a1.size() << std::endl;
    std::cout << a1.capacity() << std::endl;
    std::cout << a1.max_size() << std::endl;

    std::cout << std::endl;
    a1.reserve(10);
    std::cout << a1.size() << std::endl;
    std::cout << a1.capacity() << std::endl;
    a1.shrink_to_fit();
    std::cout << a1.size() << std::endl;
    std::cout << a1.capacity() << std::endl;

    std::cout << std::endl;
    a1.clear();
    std::cout << a1.size() << std::endl;
    std::cout << a1.capacity() << std::endl;

    std::cout << std::endl;
    a1.resize(10, 2.0);
    std::cout << a1.size() << std::endl;
    std::cout << a1.capacity() << std::endl;
    for (const auto& val : a1)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
    a1.resize(5, 3.0);
    std::cout << a1.size() << std::endl;
    std::cout << a1.capacity() << std::endl;
    for (const auto& val : a1)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
    cppmath::Vector<double> a2 = { 1, 2, 3, 4 };
    for (const auto& val : a2)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
    cppmath::Vector<double> a3({ 1, 2, 3, 4 });
    for (const auto& val : a3)
    {
        std::cout << val << std::endl;
    }

    std::cout << "TESTING ARRAY" << std::endl;

    cppmath::Array<int, std::size_t{8}> arr1 = { 1, 2, 3 };
    for (const auto& val : arr1)
    {
        std::cout << val << std::endl;
    }

    std::cout << cppmath::sum(a3) << std::endl;
    std::cout << cppmath::mean(a3) << std::endl;
    std::cout << cppmath::variance(a3) << std::endl;
    std::cout << cppmath::stddev(a3) << std::endl;

    return 0;
}