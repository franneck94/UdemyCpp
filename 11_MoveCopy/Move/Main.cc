#include <cstddef>
#include <iostream>
#include <vector>

#include "DynArray.h"

int main()
{
    std::vector<DynamicArray<int>> vec;

    vec.push_back(DynamicArray<int>{1, 1});

    return 0;
}
