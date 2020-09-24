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

Matrix Matrix::operator+(const Matrix &rhs)
{
	Matrix result;

	result.set_A(get_A() + rhs.get_A());
	result.set_B(get_B() + rhs.get_B());
	result.set_C(get_C() + rhs.get_C());
	result.set_D(get_D() + rhs.get_D());

	return result;
}

Matrix& Matrix::operator+=(const Matrix &rhs)
{
	set_A(get_A() + rhs.get_A());
	set_B(get_B() + rhs.get_B());
	set_C(get_C() + rhs.get_C());
	set_D(get_D() + rhs.get_D());

	return *this;
}

Matrix Matrix::operator-(const Matrix &rhs)
{
	Matrix result;

	result.set_A(get_A() - rhs.get_A());
	result.set_B(get_B() - rhs.get_B());
	result.set_C(get_C() - rhs.get_C());
	result.set_D(get_D() - rhs.get_D());

	return result;
}

Matrix& Matrix::operator-=(const Matrix &rhs)
{
	set_A(get_A() - rhs.get_A());
	set_B(get_B() - rhs.get_B());
	set_C(get_C() - rhs.get_C());
	set_D(get_D() - rhs.get_D());

	return *this;
}

void Matrix::print_matrix() const
{
	std::cout << m_A << ", " << m_B << std::endl;
	std::cout << m_C << ", " << m_D << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Matrix &matrix)
{
	out << matrix.m_A << ", " << matrix.m_B << std::endl;
	out << matrix.m_C << ", " << matrix.m_D << std::endl;

	return out;
}

double Matrix::get_A() const
{
	return m_A;
}

double Matrix::get_B() const
{
	return m_B;
}

double Matrix::get_C() const
{
	return m_C;
}

double Matrix::get_D() const
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