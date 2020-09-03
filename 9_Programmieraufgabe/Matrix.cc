#include <iostream>

#include "Matrix.h"

using std::cout;
using std::endl;

Matrix::Matrix()
{
	m_A = 0.0;
	m_B = 0.0;
	m_C = 0.0;
	m_D = 0.0;
}

Matrix::~Matrix()
{
}

Matrix::Matrix(const double A, const double B, const double C, const double D)
{
	m_A = A;
	m_B = B;
	m_C = C;
	m_D = D;
}

void Matrix::print_matrix() const
{
	cout << "Matrix values: " << endl;
	cout << m_A << "\t" << m_B << endl;
	cout << m_C << "\t" << m_D << endl;
	cout << endl;
}

Matrix Matrix::operator+(const Matrix &matrixB)
{
	Matrix result;

	result.set_A(get_A() + matrixB.get_A());
	result.set_B(get_B() + matrixB.get_B());
	result.set_C(get_C() + matrixB.get_C());
	result.set_D(get_D() + matrixB.get_D());

	return result;
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

Matrix &Matrix::operator+=(const Matrix &matrixB)
{
	set_A(get_A() + matrixB.get_A());
	set_B(get_B() + matrixB.get_B());
	set_C(get_C() + matrixB.get_C());
	set_D(get_D() + matrixB.get_D());

	return *this;
}

Matrix &Matrix::operator-=(const Matrix &matrixB)
{
	set_A(get_A() - matrixB.get_A());
	set_B(get_B() - matrixB.get_B());
	set_C(get_C() - matrixB.get_C());
	set_D(get_D() - matrixB.get_D());

	return *this;
}

// Aufgabe 1
Matrix Matrix::operator*(const double &scalar)
{
	Matrix result;

	result.set_A(get_A() * scalar);
	result.set_B(get_B() * scalar);
	result.set_C(get_C() * scalar);
	result.set_D(get_D() * scalar);

	return result;
}

Matrix &Matrix::operator*=(const double &scalar)
{
	set_A(get_A() * scalar);
	set_B(get_B() * scalar);
	set_C(get_C() * scalar);
	set_D(get_D() * scalar);

	return *this;
}

// Aufgabe 2
Matrix Matrix::operator/(const double &scalar)
{
	Matrix result;

	result.set_A(get_A() / scalar);
	result.set_B(get_B() / scalar);
	result.set_C(get_C() / scalar);
	result.set_D(get_D() / scalar);

	return result;
}

Matrix &Matrix::operator/=(const double &scalar)
{
	set_A(get_A() / scalar);
	set_B(get_B() / scalar);
	set_C(get_C() / scalar);
	set_D(get_D() / scalar);

	return *this;
}

// Aufgabe 3
Matrix Matrix::operator*(const Matrix &rhs)
{
	Matrix result;

	result.set_A(get_A() * rhs.get_A() + get_B() * rhs.get_C());
	result.set_B(get_A() * rhs.get_B() + get_B() * rhs.get_D());
	result.set_C(get_C() * rhs.get_A() + get_D() * rhs.get_C());
	result.set_D(get_C() * rhs.get_B() + get_D() * rhs.get_D());

	return result;
}

Matrix &Matrix::operator*=(const Matrix &rhs)
{
	return *this = (*this) * rhs;
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

void Matrix::set_A(const double wert)
{
	m_A = wert;
}

void Matrix::set_B(const double wert)
{
	m_B = wert;
}

void Matrix::set_C(const double wert)
{
	m_C = wert;
}

void Matrix::set_D(const double wert)
{
	m_D = wert;
}