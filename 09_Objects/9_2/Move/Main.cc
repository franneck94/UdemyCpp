#include <cstddef>
#include <iostream>
#include <vector>

#include "DynArray.h"

int main()
{
    auto d = std::vector<DynamicArray<int>>{};

    // Copy
    auto a = DynamicArray<int>{1, 1};
    d.push_back(a);

    // Move
    d.push_back(DynamicArray<int>{1, 1});

    return 0;
}
