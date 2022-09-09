#include <cstdint>
#include <iostream>

void f(int *p, std::uint32_t l)
{
    for (std::uint32_t i = 0; i < l; ++i)
    {
        std::cout << p[i] << std::endl;
    }
}

void h(int *p, std::uint32_t l)
{
    for (std::uint32_t i = 0; i < l; ++i)
    {
        std::cout << *(p + i) << std::endl;
    }
}

int main()
{
    int arr[3] = {1, 2, 3};

    f(arr, 3);
    h(arr, 3);
}
