#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <functional>

#include "Matrix.h"

int main()
{
	Matrix m1(1.0, 2.0, 2.0, 1.0);
	m1.print_matrix();

	Matrix m2(1.0, 0.0, 0.0, 1.0);
	m2.print_matrix();

	Matrix m3 = m1 + m2;
	m3.print_matrix();

	m3 -= m2;
	m3.print_matrix();

	return 0;
}