#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>

#include "Matrix.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
	Matrix<double> m1(2, 2, -1.3);
	std::cout << "M1: " << &m1 << std::endl;
	m1.print_matrix();

	// Copy Constructor
	Matrix<double> m2(m1);
	std::cout << "M2 (copy from M1): " << &m2 << std::endl;
	m2.print_matrix();

	// Copy Assignment
	Matrix<double> m3;
	m3 = m1;
	std::cout << "M3 (copy from M1): " << &m3 << std::endl;
	m3.print_matrix();

	return 0;
}