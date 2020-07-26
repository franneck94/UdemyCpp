#include <iostream>

#include "Matrix.h"

Matrix::Matrix() :
	m_A(0.0), m_B(0.0), m_C(0.0), m_D(0.0)
{

}

Matrix::Matrix(const double &A, const double &B, const double &C, const double &D):
	m_A(A), m_B(B), m_C(C), m_D(D)
{

}

void Matrix::print_matrix() const
{
	std::cout << m_A << ", " << m_B << std::endl;
	std::cout << m_C << ", " << m_D << std::endl;
}

// Die aufrufende Klasse ist m2
// Die Klasse rechts vom + (Argument) ist m1
// Der return Value ist m3
// m3 = m2 + m1
Matrix Matrix::operator+(const Matrix &matrixB)
{
	Matrix result;

	result.set_A(get_A() + matrixB.get_A());
	result.set_B(get_B() + matrixB.get_B());
	result.set_C(get_C() + matrixB.get_C());
	result.set_D(get_D() + matrixB.get_D());

	return result;
}

// Die aufrufende Klasse ist m2
// Die Klasse rechts vom + (Argument) ist m1
// Der return die Klasse m2 selber
// m2 += m1
Matrix& Matrix::operator+=(const Matrix &matrixB)
{
	set_A(get_A() + matrixB.get_A());
	set_B(get_B() + matrixB.get_B());
	set_C(get_C() + matrixB.get_C());
	set_D(get_D() + matrixB.get_D());

	return *this;
}

Matrix Matrix::operator-(const Matrix &matrixB)
{
	Matrix result;

	result.set_A(get_A() - matrixB.get_A());
	result.set_B(get_B() - matrixB.get_B());
	result.set_C(get_C() - matrixB.get_C());
	result.set_D(get_D() - matrixB.get_D());

	return result;
}

Matrix& Matrix::operator-=(const Matrix &matrixB)
{
	set_A(get_A() - matrixB.get_A());
	set_B(get_B() - matrixB.get_B());
	set_C(get_C() - matrixB.get_C());
	set_D(get_D() - matrixB.get_D());

	return *this;
}


const double Matrix::get_A() const
{
	return m_A;
}

const double Matrix::get_B() const
{
	return m_B;
}

const double Matrix::get_C() const
{
	return m_C;
}

const double Matrix::get_D() const
{
	return m_D;
}

void Matrix::set_A(const double &val)
{
	m_A = val;
}

void Matrix::set_B(const double &val)
{
	m_B = val;
}

void Matrix::set_C(const double &val)
{
	m_C = val;
}

void Matrix::set_D(const double &val)
{
	m_D = val;
}

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

	return 0;
}