#pragma once

#include <cstddef>
#include <vector>

template <typename T> class Matrix
{
  public:
    Matrix<T>(const unsigned int &rows, const unsigned int &cols, const T &value);
    Matrix<T>(const unsigned int &rows, const unsigned int &cols);
    ~Matrix<T>();

    void print_matrix() const;
    Matrix<T> &operator=(const Matrix<T> &matrixB);
    Matrix<T> transpose();

    Matrix operator+(const Matrix &matrixB);
    Matrix &operator+=(const Matrix &matrixB);

    Matrix operator-(const Matrix &matrixB);
    Matrix &operator-=(const Matrix &matrixB);

    Matrix operator*(const Matrix &matrixB);
    Matrix &operator*=(const Matrix &matrixB);

    Matrix operator*(const double &scalar);
    Matrix &operator*=(const double &scalar);

    Matrix operator/(const double &scalar);
    Matrix &operator/=(const double &scalar);

    unsigned int num_rows();
    unsigned int num_cols();

  private:
    unsigned int m_rows;
    unsigned int m_cols;
    const double m_epsilon;
    const T m_value;
    std::vector<std::vector<T>> m_data;
};