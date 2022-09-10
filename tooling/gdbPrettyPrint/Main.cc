#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::uint32_t length = 4;
    int *arr = new int[length];

    for (std::uint32_t i = 0; i < length; i++)
    {
        arr[i] = static_cast<int>(i);
        std::cout << arr[i] << std::endl;
    }

    delete[] arr;

    std::vector<int> vec{1, 2, 3};

    for (std::uint32_t i = 0; i < 3; i++)
    {
        std::cout << vec[i] << std::endl;
    }
}
