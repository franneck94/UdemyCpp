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

int main()
{
    const auto length = std::uint32_t{5};
    const int array[]{1, 2, 34, 100, -22};

    std::cout << array_maximum(array, length) << '\n';

    return 0;
}
