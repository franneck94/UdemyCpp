#include <iostream>

#include "DynamicArray.h"

int main()
{
    DynamicArray<double> a(1, 3);
    for (int i = 0; i != 3; ++i)
    {
        std::cout << a[i];
    }
    std::cout << std::endl;

    // Copy Constructor
    DynamicArray<double> b(a);
    for (int i = 0; i != 3; ++i)
    {
        std::cout << b[i];
    }
    std::cout << std::endl;

    // Copy Assignment Operator
    DynamicArray<double> c;
    c = a;
    for (int i = 0; i != 3; ++i)
    {
        std::cout << c[i];
    }
    std::cout << std::endl;

    return 0;
}