#include <iostream>

int array_maximum(int *array, unsigned int length)
{
    int max_val = array[0];

    for (unsigned int i = 1; i < length; ++i)
    {
        if (array[i] > max_val)
        {
            max_val = array[i];
        }
    }

    return max_val;
}


int main()
{
    unsigned int array_size = 10;

    // Heap allocation
    int *p = new int[array_size];

    for (unsigned int i = 0; i < array_size; ++i)
    {
        p[i] = i;
    }

    int maximum = array_maximum(p, array_size);

    std::cout << maximum << std::endl;

    // Heap de-allocation
    delete[] p;

    return 0;
}
