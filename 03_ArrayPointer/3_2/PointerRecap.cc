#include <cstdint>
#include <iostream>

double array_sum(const double *p_array, const std::size_t length)
{
    double sum = 0.0;

    for (std::uint32_t i = 0; i < length; i++)
    {
        sum += p_array[i];
    }

    return sum;
}

int main()
{
    std::uint32_t array_size = 10;

    // Heap Allocation
    double *p = new double[array_size];

    for (std::uint32_t i = 0; i < array_size; i++)
    {
        p[i] = i;
    }

    std::cout << array_sum(p, array_size) << '\n';

    // Heap De-Allocation
    delete[] p;

    return 0;
}
