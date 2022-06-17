#include <iostream>

#include "Matrix.h"

int main()
{
    cppmath::Matrix<double> m1(2, 2, -1.0);
    m1.print_matrix();

    cppmath::Matrix<double> m2(2, 2, 1.0);
    m2.print_matrix();

    cppmath::Matrix<double> m3 = m1 + m2;
    m3.print_matrix();

    cppmath::Matrix<double> m4 = m1 - m2;
    m4.print_matrix();

    cppmath::Matrix<double> m5 = m2 * 2;
    m5.print_matrix();

    m5 /= 2;
    m5.print_matrix();

    return 0;
}
