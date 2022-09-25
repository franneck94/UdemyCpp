#include <cstdint>
#include <iostream>

int array_maximum(const int *array, const std::uint32_t length)
{
    if (length == 0)
        return INT32_MAX;

    int result = array[0];

    for (std::uint32_t i = 1; i < length; i++)
    {
        if (array[i] > result)
        {
            result = array[i];
        }
    }

    return result;
}

void print_name(char *name)
{
    std::cout << name << std::endl;
}

int main()
{
    std::uint32_t array_size = 10;

    // Heap Allocation
    int *p = new int[array_size];

    for (int i = 0; i < array_size; i++)
    {
        p[i] = i;
    }

    std::cout << array_maximum(p, array_size) << std::endl;

    // Heap De-Allocation
    delete[] p;

    int a[5] = {4, 5, 6, 7, 8};
    std::cout << array_maximum(a, 5) << std::endl;

    char name[]{"Jan Schaffranek"};
    print_name(name);

    return 0;
}
