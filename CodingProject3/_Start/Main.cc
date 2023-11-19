#include <iostream>

#include "Matrix.h"

int main()
{
    auto m1 = Matrix<double>(2, 2, -1.0);
    m1.print_matrix();

    auto m2 = Matrix<double>(2, 2, 1.0);
    m2.print_matrix();

    auto m3 = m1 + m2;
    m3.print_matrix();

    auto m4 = m3 - m2;
    m4.print_matrix();

    return 0;
}
