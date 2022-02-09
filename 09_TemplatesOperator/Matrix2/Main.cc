#include <iostream>

#include "Matrix.h"

int main()
{
    Matrix m1(1.0, 2.0, 3.0, 4.0);
    m1.print_matrix();

    Matrix m2(-1.0, -2.0, -3.0, -4.0);
    m2.print_matrix();

    Matrix m3 = m1 + m2;
    m3.print_matrix();

    Matrix m4 = m1 - m1;
    m4.print_matrix();

    m1 -= m1;
    m1.print_matrix();

    m2 += m2;
    m2.print_matrix();

    return 0;
}
