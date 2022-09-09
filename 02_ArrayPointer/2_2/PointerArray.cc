#include <iostream>

int main()
{
    unsigned int array_size = 10;

    // Heap allocation
    int *p = new int[array_size];

    for (unsigned int i = 0; i < array_size; ++i)
    {
        p[i] = i;
    }

    // .....

    for (unsigned int i = 0; i < array_size; ++i)
    {
        std::cout << p[i] << std::endl;
    }

    // Heap de-allocation
    delete[] p;

    return 0;
}
