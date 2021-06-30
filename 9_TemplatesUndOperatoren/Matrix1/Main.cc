#include <iostream>

#include "Matrix.h"

int main()
{
    Matrix m1(1.0, 2.0, 3.0, 4.0);
    m1.print_matrix();

    Matrix m2;
    m2.print_matrix();

    return 0;
}
