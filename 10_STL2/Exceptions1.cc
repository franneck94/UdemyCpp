#include <exception>
#include <iostream>

double div(const double x, const double y)
{
    if (y == 0.0)
    {
        throw std::invalid_argument("Divisor is zero!");
    }

    return x / y;
}

int main()
{
    const auto x = 10.0;
    const auto y = 0.0;

    std::cout << "We will compute (x/y)" << '\n';
    try
    {
        const auto z = div(x, y);
        std::cout << "x/y = " << z << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
