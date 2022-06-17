#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace cppmath
{

template <typename T>
class Matrix
{
public:
    using MatrixDataType = std::vector<std::vector<T>>;

    Matrix() = delete;
    Matrix(std::size_t rows, std::size_t cols);
    Matrix(std::size_t rows, std::size_t cols, const T &value);

    Matrix operator+(const Matrix &rhs);
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs);
    Matrix &operator-=(const Matrix &rhs);
    Matrix operator*(const T &scalar);
    Matrix &operator*=(const T &scalar);
    Matrix operator/(const T &scalar);
    Matrix &operator/=(const T &scalar);
    Matrix operator*(const Matrix &rhs);
    Matrix &operator*=(const Matrix &rhs);

    void print_matrix() const;

    std::size_t num_rows() const;
    std::size_t num_cols() const;

private:
    std::size_t m_rows;
    std::size_t m_cols;
    MatrixDataType m_data;
};

} // namespace cppmath
