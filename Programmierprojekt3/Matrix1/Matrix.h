#pragma once

#include <iostream>

template <typename T> class Matrix
{
  public:
    Matrix() = default;

    Matrix operator+(const Matrix &rhs);
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs);
    Matrix &operator-=(const Matrix &rhs);
    Matrix operator*(const double &scalar);
    Matrix &operator*=(const double &scalar);
    Matrix operator/(const double &scalar);
    Matrix &operator/=(const double &scalar);
    Matrix operator*(const Matrix &rhs);
    Matrix &operator*=(const Matrix &rhs);

    void print_matrix() const;

  private:
};

template <typename T> Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs)
{
    Matrix result;

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{

    return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs)
{
    Matrix result;

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{

    return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const double &scalar)
{
    Matrix<T> result;

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator*=(const double &scalar)
{

    return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator/(const double &scalar)
{
    Matrix result;

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator/=(const double &scalar)
{

    return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs)
{
    Matrix<T> result;

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    *this = (*this) * rhs;

    return *this;
}

template <typename T> void Matrix<T>::print_matrix() const
{
    std::cout << std::endl;
}
