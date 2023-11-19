#include <iostream>

#include "Matrix.h"

int main()
{
    auto m1 = Matrix<double>{1.0, 2.0, 3.0, 4.0};
    m1.print_matrix();

    auto m2 = Matrix<double>{1.0, 2.0, 3.0, 4.0};
    m2.print_matrix();

    auto m3 = m1 * 2;
    m3.print_matrix();

    m3 = m3 / 2;
    m3.print_matrix();

    return 0;
}
