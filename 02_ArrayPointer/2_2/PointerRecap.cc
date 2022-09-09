#include <iostream>

double array_sum(const double *p_array, const unsigned int &length)
{
    double sum = 0.0;

    for (unsigned int i = 0; i < length; i++)
    {
        sum += p_array[i];
    }

    return sum;
}

int main()
{
    unsigned int array_size = 10;

    // Heap Allocation
    double *p = new double[array_size];

    for (unsigned int i = 0; i < array_size; i++)
    {
        p[i] = i;
    }

    std::cout << array_sum(p, array_size) << std::endl;

    // Heap De-Allocation
    delete[] p;

    return 0;
}
