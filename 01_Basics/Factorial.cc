#include <iostream>

unsigned int faculty(unsigned int n)
{
    if (n > 1)
    {
        return n * faculty(n - 1);
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    unsigned int n = 5;
    unsigned int n_fac = faculty(n);

    std::cout << n << "! = " << n_fac << std::endl;

    return 0;
}
