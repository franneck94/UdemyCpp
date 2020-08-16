//#include <iostream>
//
//#include "Matrix.h"
//
//Matrix::Matrix() :
//	m_A(0.0), m_B(0.0), m_C(0.0), m_D(0.0)
//{
//
//}
//
//Matrix::Matrix(const double &A, const double &B, const double &C, const double &D):
//	m_A(A), m_B(B), m_C(C), m_D(D)
//{
//
//}
//
//void Matrix::print_matrix() const
//{
//	std::cout << m_A << ", " << m_B << std::endl;
//	std::cout << m_C << ", " << m_D << std::endl;
//}
//
//const double Matrix::get_A() const
//{
//	return m_A;
//}
//
//const double Matrix::get_B() const
//{
//	return m_B;
//}
//
//const double Matrix::get_C() const
//{
//	return m_C;
//}
//
//const double Matrix::get_D() const
//{
//	return m_D;
//}
//
//void Matrix::set_A(const double &val)
//{
//	m_A = val;
//}
//
//void Matrix::set_B(const double &val)
//{
//	m_B = val;
//}
//
//void Matrix::set_C(const double &val)
//{
//	m_C = val;
//}
//
//void Matrix::set_D(const double &val)
//{
//	m_D = val;
//}
//
//int main()
//{
//	Matrix m1(1.0, 2.0, 3.0, 4.0);
//	m1.print_matrix();
//
//	Matrix m2(1.0, 2.0, 3.0, 4.0);
//	m2.print_matrix();
//
//	m1 + m2;
//
//	return 0;
//}