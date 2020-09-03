#include <iostream>
#include <string>

#include "DynArrayCopy.h"

using std::string;

int main()
{
    DynamicArray<double> a(1, 3);
    std::cout << "Adresse a: " << &a << std::endl;
    for (int i = 0; i != 3; ++i)
    {
        std::cout << a[i];
    }
    std::cout << std::endl;

    // Copy Constructor
    DynamicArray<double> b(a);
    std::cout << "Adresse b: " << &b << std::endl;
    for (int i = 0; i != 3; ++i)
    {
        std::cout << b[i];
    }
    std::cout << std::endl;

    // Copy Assignment Operator
    DynamicArray<double> c = a;
    std::cout << "Adresse c: " << &c << std::endl;
    for (int i = 0; i != 3; ++i)
    {
        std::cout << c[i];
    }
    std::cout << std::endl;

    return 0;
}