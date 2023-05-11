#include <cstdint>
#include <iostream>

int main()
{
    auto array_size = std::size_t{10};

    // Heap Allocation
    auto *arr = new std::int32_t[array_size];

    for (std::size_t i = 0; i < array_size; i++)
    {
        arr[i] = i;
    }

    // ...

    for (std::size_t i = 0; i < array_size; i++)
    {
        std::cout << arr[i] << '\n';
    }

    // Heap De-Allocation
    delete[] arr;

    return 0;
}
