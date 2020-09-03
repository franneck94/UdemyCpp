#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>

#include "Matrix6.h"

using std::string;
using std::vector;

int main()
{
	Matrix<double> m1(2, 2, 3.5);
	m1.print_matrix();
	m1 *= 3;
	m1.print_matrix();
	m1 /= 0;
	m1.print_matrix();

	Matrix<double> m2(2, 2, 1.5);
	Matrix<double> m3(2, 2, 1.2);

	m2.print_matrix();
	m2 += m3;
	m2.print_matrix();
	m2 -= m3;
	m2.print_matrix();

	Matrix<double> m4(2, 2, 1.5);
	Matrix<double> m5(2, 2, 2.0);

	m4.print_matrix();
	m4 *= m5;
	m4.print_matrix();

	Matrix<double> m6(2, 3, 1.5);

	m6.print_matrix();
	m6 = m6.transpose();
	m6.print_matrix();

	return 0;
}