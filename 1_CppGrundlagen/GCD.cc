#include <iostream>

int ggt(int a, int b)
{
    // b ist groesser
    if (a < b)
    {
        for (int i = a; a >= 1; i--)
        {
            if (a % i == 0 && b % i == 0)
                return i;
        }
    }
    // a ist groesser
    else
    {
        for (int i = b; i >= 1; i--)
        {
            if (a % i == 0 && b % i == 0)
                return i;
        }
    }
}

int ggt_recursiv(int a, int b)
{
    if (a > 0)
        return ggt_recursiv(b % a, a);
    else
        return b;
}

int main()
{
    int z1 = 123;
    int z2 = 15;

    int z3 = ggt_recursiv(z1, z2);
    std::cout << "ggt(" << z1 << "," << z2 << ") = " << z3 << std::endl;

    return 0;
}