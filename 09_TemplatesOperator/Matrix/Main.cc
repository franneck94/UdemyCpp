#include <iostream>

#include "Matrix.h"

int main()
{
    Matrix m1(1.0, 2.0, 3.0, 4.0);
    Matrix m2(-1.0, -2.0, -3.0, -4.0);

    auto m3 = m1 + m2;
    m3.print_matrix();
    auto m4 = m1 + m3;
    m4.print_matrix();
    m2 -= m1;
    m2.print_matrix();

    return 0;
}
