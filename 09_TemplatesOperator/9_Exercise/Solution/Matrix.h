#pragma once

class Matrix
{
public:
    Matrix();
    Matrix(const double &A, const double &B, const double &C, const double &D);

    Matrix operator+(const Matrix &rhs);
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs);
    Matrix &operator-=(const Matrix &rhs);

    // Exercise 1
    Matrix operator*(const double &scalar);
    Matrix &operator*=(const double &scalar);
    // Exercise 2
    Matrix operator/(const double &scalar);
    Matrix &operator/=(const double &scalar);
    // Excercise 3
    Matrix operator*(const Matrix &rhs);
    Matrix &operator*=(const Matrix &rhs);

    void print_matrix() const;

    double get_A() const;
    double get_B() const;
    double get_C() const;
    double get_D() const;

    void set_A(const double &new_A);
    void set_B(const double &new_B);
    void set_C(const double &new_C);
    void set_D(const double &new_D);

private:
    double m_A;
    double m_B;
    double m_C;
    double m_D;
};
