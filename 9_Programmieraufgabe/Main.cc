#include <iostream>

#include "Matrix.h"

int main()
{
	Matrix m1(1.0, 2.0, 2.0, 1.0);
	m1.print_matrix();

	Matrix m2(1.0, 0.0, 0.0, 1.0);
	m2.print_matrix();

	std::cout << "m3 = m1 + m2" << std::endl;
	Matrix m3 = m1 + m2;
	m3.print_matrix();

	std::cout << "m3 -= m2" << std::endl;
	m3 -= m2;
	m3.print_matrix();

	std::cout << "m3 *= 3" << std::endl;
	m3 *= 3.0;
	m3.print_matrix();

	std::cout << "m3 /= 3" << std::endl;
	m3 /= 3.0;
	m3.print_matrix();

	std::cout << "m3 *= m2" << std::endl;
	m3 *= m2;
	m3.print_matrix();

	return 0;
}