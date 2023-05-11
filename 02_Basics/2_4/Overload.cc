#include <cstdint>
#include <iostream>

double max(double a, double b)
{
    return a > b ? a : b;
}

std::int32_t max(std::int32_t a, std::int32_t b)
{
    return a > b ? a : b;
}

int main()
{
    double da = 1.0;
    double db = 3.0;
    std::cout << max(da, db) << '\n';

    std::int32_t ia = 1;
    std::int32_t ib = 3;
    std::cout << max(ia, ib) << '\n';

    return 0;
}
