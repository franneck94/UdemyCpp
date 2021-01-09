#include <iostream>

unsigned long long factorial(unsigned int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    unsigned int n = 100;
    unsigned long long n_fac = factorial(n);

    std::cout << "n! = " << n_fac << std::endl;

    return 0;
}