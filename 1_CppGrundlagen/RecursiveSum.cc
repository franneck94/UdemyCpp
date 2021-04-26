#include <iostream>

unsigned int sum(unsigned int n)
{
    if (n > 1)
    {
        return n + sum(n - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    unsigned int n = 10000;
    unsigned long long n_sum = sum(n);

    std::cout << "sum from 1 to n = " << n_sum << std::endl;

    return 0;
}
