#include <cstdint>
#include <iostream>

int main()
{
    std::uint32_t array_size = 10;

    // Heap allocation
    int *p = new int[array_size];

    for (std::uint32_t i = 0; i < array_size; ++i)
    {
        p[i] = i;
    }

    // .....

    for (std::uint32_t i = 0; i < array_size; ++i)
    {
        std::cout << p[i] << std::endl;
    }

    // Heap de-allocation
    delete[] p;

    return 0;
}
