#include <iostream>

#include "Matrix.h"

int main()
{
    cppmath::Matrix<double> m1(2, 2, 0.0);
    m1.print_matrix();

    cppmath::Matrix<double> m2(2, 2, 1.0);
    m2.print_matrix();

    return 0;
}
