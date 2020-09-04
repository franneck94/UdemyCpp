#include <iostream>

#include "Matrix.h"

int main()
{
    Matrix<double> m1(2, 2, 3.5);
    Matrix<double> m2(2, 3, 3.5);
    Matrix<double> m3 = m1 + m2;

    Matrix<double> m4(2, 3, 3.5);
    Matrix<double> m5(2, 3, 3.5);
    Matrix<double> m6 = m4 * m5;

    return 0;
}