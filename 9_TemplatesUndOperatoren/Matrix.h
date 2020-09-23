#pragma once

class Matrix
{
public:
	Matrix();
	Matrix(const double &A, const double &B, const double &C, const double &D);
	~Matrix() = default;

	void print_matrix() const;

	const double get_A() const;
	const double get_B() const;
	const double get_C() const;
	const double get_D() const;

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