#include <cstddef>
#include <iostream>

#include "AlgoArray.h"
#include "DynArray.h"

int main()
{
    DynamicArray<int> a1(1.0, 3);
    DynamicArray<int> a2(-1.0, 4);

    DynamicArray<int> a3 = a2; // Copy constructor
    DynamicArray<int> a4(a2); // Copy constructor
    DynamicArray<int> a5{ a2 }; // Copy constructor
    DynamicArray<int> a6 = { a2 }; // Copy constructor

    a1 = a2; // Copy assignment operator

    return 0;
}
