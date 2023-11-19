#include <cstdint>
#include <iostream>

void print_array1(const std::int32_t *arr, const std::size_t len)
{
    for (std::size_t i = 0; i < len; i++)
    {
        std::cout << arr[i] << '\n';
    }
}

void print_array2(const std::int32_t *arr, const std::size_t len)
{
    for (std::size_t i = 0; i < len; i++)
    {
        std::cout << *(arr + i) << '\n';
    }
}

int main()
{
    constexpr std::size_t arr_len = 4U;
    const std::int32_t values[arr_len]{1, 2, 3, 4};

    print_array1(values, arr_len);
    print_array2(values, arr_len);

    return 0;
}
