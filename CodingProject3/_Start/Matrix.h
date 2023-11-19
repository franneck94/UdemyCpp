#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename T>
class Matrix
{
public:
    using MatrixDataType = std::vector<std::vector<T>>;

    Matrix() = delete;
    Matrix(const std::size_t rows, const std::size_t cols);
    Matrix(const std::size_t rows, const std::size_t cols, const T value);
    ~Matrix() noexcept = default;

    Matrix(const Matrix &other) = default;
    Matrix &operator=(const Matrix &other) = default;
    Matrix(Matrix &&other) noexcept = default;
    Matrix &operator=(Matrix &&other) noexcept = default;

    Matrix operator+(const Matrix &rhs) const;
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs) const;
    Matrix &operator-=(const Matrix &rhs);

    Matrix operator*(const T &scalar) const;
    Matrix &operator*=(const T &scalar);
    Matrix operator/(const T &scalar) const;
    Matrix &operator/=(const T &scalar);

    Matrix operator*(const Matrix &rhs) const;
    Matrix &operator*=(const Matrix &rhs);

    void print_matrix() const;

    std::size_t num_rows() const;
    std::size_t num_cols() const;

private:
    std::size_t m_rows;
    std::size_t m_cols;
    MatrixDataType m_data;
};

template <typename T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols)
{
}

template <typename T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols, const T value)
{
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
    auto result = Matrix(m_rows, m_cols);


    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
    auto result = Matrix(m_rows, m_cols);

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const
{
    auto result = Matrix(m_rows, m_cols);

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar) const
{
    auto result = Matrix(m_rows, m_cols);

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const
{
    auto result = Matrix(m_rows, m_cols);

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &rhs)
{

    return *this;
}

template <typename T>
std::size_t Matrix<T>::num_rows() const
{
}

template <typename T>
std::size_t Matrix<T>::num_cols() const
{
}

template <typename T>
void Matrix<T>::print_matrix() const
{
    for (const auto &row : m_data)
    {
        for (const auto val : row)
        {
            std::cout << val << ", ";
        }

        std::cout << '\n';
    }
}
