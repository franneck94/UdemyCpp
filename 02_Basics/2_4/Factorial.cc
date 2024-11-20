#include <iostream>

unsigned int faculty(unsigned int n)
{
    if (n > 1)
    {
        return n * faculty(n - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    unsigned int n = 0;
    unsigned int n_fac = faculty(n);

    std::cout << n << "! = " << n_fac << std::endl;

    return 0;
}
