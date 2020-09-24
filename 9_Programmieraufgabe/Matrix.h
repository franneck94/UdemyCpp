#pragma once

#include <iostream>

class Matrix
{
public:
	Matrix();
	Matrix(const double &A, const double &B, const double &C, const double &D);

	Matrix operator+(const Matrix &rhs);
	Matrix& operator+=(const Matrix &rhs);
	Matrix operator-(const Matrix &rhs);
	Matrix& operator-=(const Matrix &rhs);

	// Aufgabe 1
	Matrix operator*(const double &scalar);
	Matrix& operator*=(const double &scalar);
	// Aufgabe 2
	Matrix operator/(const double &scalar);
	Matrix& operator/=(const double &scalar);
	// Aufgabe 3
	Matrix operator*(const Matrix &rhs);
	Matrix& operator*=(const Matrix &rhs);

	void print_matrix() const;
	friend std::ostream& operator<<(std::ostream &out, const Matrix &matrix);

	double get_A() const;
	double get_B() const;
	double get_C() const;
	double get_D() const;

	void set_A(const double &val);
	void set_B(const double &val);
	void set_C(const double &val);
	void set_D(const double &val);

private:
	double m_A;
	double m_B;
	double m_C;
	double m_D;
};