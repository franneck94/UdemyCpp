#include <iostream>

#include "Matrix.h"

int main()
{
    auto m1 = Matrix<double>(2, 2, -1.0);
    m1.print_matrix();

    auto m2 = Matrix<double>(3, 2, 1.0);
    m2.print_matrix();

    try
    {
        auto m3 = m1 * m2;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
