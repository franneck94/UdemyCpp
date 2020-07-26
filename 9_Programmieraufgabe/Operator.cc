#include <iostream>

#include "Matrix.h"

using std::cout;
using std::endl;

int main()
{
	Matrix m1(1.0, 2.0, 2.0, 1.0);
	m1.print_matrix();

	Matrix m2(1.0, 0.0, 0.0, 1.0);
	m2.print_matrix();

	cout << "m3 = m1 + m2" << endl;
	Matrix m3 = m1 + m2;
	m3.print_matrix();

	cout << "m3 -= m2" << endl;
	m3 -= m2;
	m3.print_matrix();

	cout << "m3 *= 3" << endl;
	m3 *= 3.0;
	m3.print_matrix();

	cout << "m3 /= 3" << endl;
	m3 /= 3.0;
	m3.print_matrix();

	cout << "m3 *= m2" << endl;
	m3 *= m2;
	m3.print_matrix();

	return 0;
}