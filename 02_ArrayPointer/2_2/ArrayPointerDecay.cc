#include <cstdint>
#include <iostream>

// array to pointer decay
void print_array(int *array, const std::uint32_t length)
{
    for (std::uint32_t i = 0; i < length; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}

int main()
{
    int arr1[]{1, 2, 3};
    print_array(arr1, 3);

    auto *arr2 = new int[3];
    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 3;
    print_array(arr2, 3);
}
