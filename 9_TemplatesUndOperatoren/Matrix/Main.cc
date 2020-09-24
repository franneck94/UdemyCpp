#include <iostream>

#include "Matrix.h"

int main()
{
	Matrix m1(1.0, 2.0, 3.0, 4.0);
	m1.print_matrix();
	std::cout << std::endl;

	Matrix m2(1.0, 2.0, 3.0, 4.0);
	m2.print_matrix();
	std::cout << std::endl;

	Matrix m3 = m1 + m2;
	m3.print_matrix();
	std::cout << std::endl;

	m2 += m1;
	m2.print_matrix();
	std::cout << std::endl;

	std::cout << m2 << std::endl;

	return 0;
}