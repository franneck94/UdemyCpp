#include <iostream>

int max(const int &a, const int &b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

double max(const double &a, const double &b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    int num1 = 4;
    int num2 = 0;

    double num3 = 10.0;
    double num4 = 10.5;

    std::cout << max(num1, num2) << std::endl;
    std::cout << max(num3, num4) << std::endl;

    return 0;
}
