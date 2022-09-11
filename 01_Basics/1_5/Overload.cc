#include <iostream>

double max(double a, double b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

int main()
{
    int a = 2;
    int b = 3;

    std::cout << max(a, b) << std::endl;

    double c = 2;
    double d = 3;

    std::cout << max(c, d) << std::endl;

    return 0;
}
