#include <iostream>

#include "Matrix.h"

int main()
{
    cppmath::Matrix<double> m1(2, 2, -1.0);
    cppmath::Matrix<double> m2(3, 2, 1.0);

    m1.print_matrix();
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
