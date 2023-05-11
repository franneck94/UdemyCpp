#include <cstdint>
#include <iostream>

int array_maximum(const std::int32_t *array, const std::size_t length)
{
    if (length == 0)
        return INT32_MAX;

    int result = array[0];

    for (std::size_t i = 1; i < length; i++)
    {
        if (array[i] > result)
        {
            result = array[i];
        }
    }

    return result;
}

void print_name(const char *name)
{
    std::cout << name << '\n';
}

int main()
{
    constexpr std::size_t array_size = 3U;

    // Heap Allocation
    std::int32_t *p = new std::int32_t[array_size];

    for (std::size_t i = 0; i < array_size; i++)
    {
        p[i] = static_cast<std::int32_t>(i);
    }

    std::cout << array_maximum(p, array_size) << '\n';

    // Heap De-Allocation
    delete[] p;

    std::int32_t a[array_size] = {4, 5, 6};
    std::cout << array_maximum(a, array_size) << '\n';

    const char name[]{"Jan Schaffranek"};
    print_name(name);

    return 0;
}
