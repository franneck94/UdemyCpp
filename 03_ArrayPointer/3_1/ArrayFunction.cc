#include <cstdint>
#include <iostream>

void print_array(const std::int32_t arr[], const std::size_t len)
{
    for (std::size_t i = 0; i < len; i++)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    constexpr std::size_t arr_len = 4U;
    const std::int32_t values[arr_len]{1, 2, 3, 4};

    print_array(values, arr_len);

    return 0;
}
