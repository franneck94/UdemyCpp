#pragma once

class Matrix
{
public:
	Matrix();
	~Matrix();
	Matrix(const double A, const double B, const double C, const double D);
	void print_matrix() const;

	Matrix operator+(const Matrix &matrixB);
	Matrix operator-(const Matrix &matrixB);
	Matrix &operator+=(const Matrix &matrixB);
	Matrix &operator-=(const Matrix &matrixB);

	// Aufgabe 1
	Matrix operator*(const double &scalar);
	Matrix &operator*=(const double &scalar);
	// Aufgabe 2
	Matrix operator/(const double &scalar);
	Matrix &operator/=(const double &scalar);
	// Aufgabe 3
	Matrix operator*(const Matrix &rhs);
	Matrix &operator*=(const Matrix &rhs);

	const double get_A() const;
	const double get_B() const;
	const double get_C() const;
	const double get_D() const;

	void set_A(const double wert);
	void set_B(const double wert);
	void set_C(const double wert);
	void set_D(const double wert);

private:
	double m_A;
	double m_B;
	double m_C;
	double m_D;
};