#include <iostream>

#include "Matrix.h"

Matrix::Matrix() : m_A(0.0), m_B(0.0), m_C(0.0), m_D(0.0)
{
}

Matrix::Matrix(const double &A,
               const double &B,
               const double &C,
               const double &D)
    : m_A(A), m_B(B), m_C(C), m_D(D)
{
}

void Matrix::print_matrix() const
{
    std::cout << m_A << " " << m_B << '\n';
    std::cout << m_C << " " << m_D << "\n\n";
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

void Matrix::set_A(const double &new_A)
{
    m_A = new_A;
}

void Matrix::set_B(const double &new_B)
{
    m_B = new_B;
}

void Matrix::set_C(const double &new_C)
{
    m_C = new_C;
}

void Matrix::set_D(const double &new_D)
{
    m_D = new_D;
}
