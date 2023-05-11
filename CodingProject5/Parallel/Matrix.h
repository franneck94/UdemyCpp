#pragma once

#include <algorithm>
#include <concepts>
#include <exception>
#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>

template <std::floating_point T>
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

    [[nodiscard]] Matrix operator+(const Matrix &rhs) const;
    [[nodiscard]] Matrix &operator+=(const Matrix &rhs);
    [[nodiscard]] Matrix operator-(const Matrix &rhs) const;
    [[nodiscard]] Matrix &operator-=(const Matrix &rhs);

    [[nodiscard]] Matrix operator*(const T &scalar) const;
    [[nodiscard]] Matrix &operator*=(const T &scalar);
    [[nodiscard]] Matrix operator/(const T &scalar) const;
    [[nodiscard]] Matrix &operator/=(const T &scalar);

    [[nodiscard]] Matrix operator*(const Matrix &rhs) const;
    [[nodiscard]] Matrix &operator*=(const Matrix &rhs);

    void print_matrix() const;

    [[nodiscard]] std::size_t num_rows() const;
    [[nodiscard]] std::size_t num_cols() const;


private:
    void dot(const Matrix &matrixA,
             const Matrix &matrixB,
             Matrix &result) const;
    void parallel_dot(const Matrix &matrixA,
                      const Matrix &matrixB,
                      Matrix &result) const;

    std::size_t m_rows;
    std::size_t m_cols;
    MatrixDataType m_data;
};

template <std::floating_point T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols)
    : m_rows(rows), m_cols(cols), m_data(m_rows, std::vector<T>(m_cols, T{}))
{
}

template <std::floating_point T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols, const T value)
    : m_rows(rows), m_cols(cols), m_data(m_rows, std::vector<T>(m_cols, value))
{
}

template <std::floating_point T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!"));
    }

    auto result = Matrix(m_rows, m_cols);

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       result.m_data[i].begin(),
                       std::plus<T>());
    }

    return result;
}

template <std::floating_point T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!"));
    }

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       m_data[i].begin(),
                       std::plus<T>());
    }

    return *this;
}

template <std::floating_point T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!"));
    }

    auto result = Matrix(m_rows, m_cols);

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       result.m_data[i].begin(),
                       std::minus<T>());
    }

    return result;
}

template <std::floating_point T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!"));
    }

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       m_data[i].begin(),
                       std::minus<T>());
    }

    return *this;
}

template <std::floating_point T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const
{
    auto result = Matrix(m_rows, m_cols);

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       result.m_data[i].begin(),
                       [](const T &val) { return val * scalar; });
    }

    return result;
}

template <std::floating_point T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       m_data[i].begin(),
                       [](const T &val) { return val * scalar; });
    }

    return *this;
}

template <std::floating_point T>
Matrix<T> Matrix<T>::operator/(const T &scalar) const
{
    if (scalar == T{})
    {
        throw(std::invalid_argument("Div by zero!"));
    }

    auto result = Matrix(m_rows, m_cols);

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       result.m_data[i].begin(),
                       [](const T &val) { return val / scalar; });
    }

    return result;
}

template <std::floating_point T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{
    if (scalar == T{})
    {
        throw(std::invalid_argument("Div by zero!"));
    }

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       m_data[i].begin(),
                       [](const T &val) { return val / scalar; });
    }

    return *this;
}

template <std::floating_point T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const
{
    if (m_cols != rhs.m_rows)
    {
        throw(std::invalid_argument("Dimensions do not match!"));
    }

    auto result = Matrix(m_rows, rhs.m_cols);

    if ((m_rows < 250 && m_cols < 250) ||
        (rhs.m_rows < 250 && rhs.m_cols < 250))
    {
        dot(*this, rhs, result);
    }
    else
    {
        parallel_dot(*this, rhs, result);
    }

    return result;
}

template <std::floating_point T>
void Matrix<T>::dot(const Matrix<T> &matrixA,
                    const Matrix<T> &matrixB,
                    Matrix<T> &result) const
{
    for (std::size_t i = 0; i != matrixA.m_rows; ++i)
    {
        for (std::size_t k = 0; k != matrixB.m_rows; ++k)
        {
            for (std::size_t j = 0; j != matrixB.m_cols; ++j)
            {
                result.m_data[i][j] =
                    result.m_data[i][j] +
                    matrixA.m_data[i][k] * matrixB.m_data[k][j];
            }
        }
    }
}

template <std::floating_point T>
void Matrix<T>::parallel_dot(const Matrix<T> &matrixA,
                             const Matrix<T> &matrixB,
                             Matrix<T> &result) const
{
    std::int32_t i = 0;
    std::int32_t j = 0;
    std::int32_t k = 0;

#pragma omp parallel for shared(result) private(i, j, k) num_threads(14)
    for (i = 0; i < matrixA.m_rows; ++i)
    {
        for (k = 0; k < matrixB.m_rows; ++k)
        {
            for (j = 0; j < matrixB.m_cols; ++j)
            {
                result.m_data[i][j] =
                    result.m_data[i][j] +
                    matrixA.m_data[i][k] * matrixB.m_data[k][j];
            }
        }
    }
}

template <std::floating_point T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    if (m_cols != rhs.m_rows)
    {
        throw(std::invalid_argument("Dimensiosn do not match!"));
    }

    *this = (*this) * rhs;

    return *this;
}

template <std::floating_point T>
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

template <std::floating_point T>
std::size_t Matrix<T>::num_rows() const
{
    return m_rows;
}

template <std::floating_point T>
std::size_t Matrix<T>::num_cols() const
{
    return m_cols;
}
