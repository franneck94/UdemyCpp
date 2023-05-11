#include <iostream>

#include "Matrix.h"

int main()
{
    const auto m = Matrix<double>{1.0, 2.0, 3.0, 4.0};
    m.print_matrix();

    const auto m2 = Matrix<float>{1.0f, 2.0f, 3.0f, 4.0f};
    m2.print_matrix();

    return 0;
}
