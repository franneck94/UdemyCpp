#include <iostream>

constexpr int fac(int n)
{
    if (n > 1)
        return n * fac(n - 1);
    else
        return 1;
}

int main()
{
    // Compile-Time bekannt:
    // Runtime bekannt:

    int a[fac(3)] = {};

    return 0;
}