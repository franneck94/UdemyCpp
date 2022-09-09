#include <cstdint>
#include <iostream>

// int* input_array <=> int input_array[]
int array_maximum(int *input_array, std::uint32_t length)
{
    int current_max_value = 0;

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            current_max_value = input_array[i];
        }
        else if (input_array[i] > current_max_value)
        {
            current_max_value = input_array[i];
        }
    }

    return current_max_value;
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
