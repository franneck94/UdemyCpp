#include <iostream>

double div(double x, double y)
{
    if (y == 0.0)
    {
        throw "Division by zero!";
    }

    return x / y;
}

int main()
{
    double x = 10.0;
    double y;

    std::cout << "We will compute (x/y)" << '\n';
    std::cout << "Please enter a value for y=";
    std::cin >> y;
    std::cout << '\n';

    try
    {
        double z = div(x, y);
        std::cout << "x/y = " << z << '\n';
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }

    return 0;
}
