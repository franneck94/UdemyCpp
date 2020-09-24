#include <iostream>

#include "Matrix.h"

int main()
{
    cppmath::Matrix<double> m1(2, 2, 3.5);
    cppmath::Matrix<double> m2(2, 2, 3.5);
    cppmath::Matrix<double> m3 = m1 + m2;
    m3.print_matrix();

    cppmath::Matrix<double> m4(2, 3, 3.5);
    cppmath::Matrix<double> m5(3, 2, 3.5);
    cppmath::Matrix<double> m6 = m4 * m5;
    m6.print_matrix();

    return 0;
}