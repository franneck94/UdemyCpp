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
    int a[fac(3)] = {};

    int b = 3;
    fac(b);

    return 0;
}
