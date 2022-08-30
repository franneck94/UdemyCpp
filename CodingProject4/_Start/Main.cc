#include <iostream>

#include "Matrix.h"

int main()
{
    cppmath::Matrix<double> m1(2, 2, -1.0);
    cppmath::Matrix<double> m2(3, 2, 1.0);

    m1.print_matrix();
    m2.print_matrix();

    return 0;
}
