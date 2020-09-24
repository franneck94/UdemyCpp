#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <exception>

namespace cppmath
{

constexpr double EPS = 1e-6;

template <typename T>
class Matrix
{
public:
	Matrix() = delete;
	Matrix(std::size_t rows, std::size_t cols, const T &value);
	Matrix(std::size_t rows, std::size_t cols);

	void print_matrix() const;
	Matrix transpose();

	Matrix operator+(const Matrix &rhs);
	Matrix& operator+=(const Matrix &rhs);
	Matrix operator-(const Matrix &rhs);
	Matrix& operator-=(const Matrix &rhs);
	Matrix operator*(const Matrix &rhs);
	Matrix& operator*=(const Matrix &rhs);
	Matrix operator*(const T &scalar);
	Matrix& operator*=(const T &scalar);
	Matrix operator/(const T &scalar);
	Matrix& operator/=(const T &scalar);

	std::size_t num_rows() const;
	std::size_t num_cols() const;

private:
	std::size_t m_rows;
	std::size_t m_cols;
	std::vector<std::vector<T>> m_data;
};

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const T &value) : 
	m_rows(rows),
	m_cols(cols),
	m_data(m_rows, std::vector<T>(m_cols, value))
{
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols) :
	m_rows(rows),
	m_cols(cols),
	m_data(m_rows, std::vector<T>(m_cols, 0))
{
}

template <typename T>
void Matrix<T>::print_matrix() const
{
	for (std::size_t i = 0; i != m_rows; ++i)
	{
		for (std::size_t j = 0; j != m_cols; ++j)
		{
			std::cout << m_data[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

template <typename T>
Matrix<T> Matrix<T>::transpose()
{
	Matrix<T> result(m_cols, m_rows);

	for (std::size_t i = 0; i != m_rows; ++i)
	{
		for (std::size_t j = 0; j != m_cols; ++j)
		{
			result.m_data[j][i] = m_data[i][j];
		}
	}

	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs)
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of Rows not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of Cols not equal!"));
    }

    Matrix<T> result(m_rows, m_cols);

    for (std::size_t i = 0; i != m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                    m_data[i].end(),
                    rhs.m_data[i].begin(),
                    result.m_data[i].begin(), 
                    std::plus<T>()
                    );
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &rhs)
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of Rows not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of Cols not equal!"));
    }

    for (std::size_t i = 0; i != m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                        m_data[i].end(),
                        rhs.m_data[i].begin(),
                        m_data[i].begin(),
                        std::plus<T>()
                    );
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &rhs)
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of Rows not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of Cols not equal!"));
    }

    Matrix<T> result(m_rows, m_cols);

    for (std::size_t i = 0; i != m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                        m_data[i].end(),
                        rhs.m_data[i].begin(),
                        result.m_data[i].begin(), 
                        std::minus<T>()
                    );
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix &rhs)
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of Rows not equal!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of Cols not equal!"));
    }

    for (std::size_t i = 0; i != m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                        m_data[i].end(),
                        rhs.m_data[i].begin(),
                        m_data[i].begin(),
                        std::minus<T>()
                    );
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs)
{
    if (m_cols != rhs.m_rows)
    {
        throw(std::invalid_argument("Dimensions does not match!"));
    }

    Matrix<T> result(m_rows, rhs.m_cols);

    for (std::size_t i = 0; i != m_rows; ++i)
    {
        for (std::size_t j = 0; j != rhs.m_cols; ++j)
        {
            for (std::size_t k = 0; k != rhs.m_rows; ++k)
            {
                result.m_data[i][j] = result.m_data[i][j] + m_data[i][k] * rhs.m_data[k][j];
            }
        }
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &rhs)
{
	*this = (*this) * rhs;
	
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar)
{
	Matrix<T> result(m_rows, m_cols);

	for (std::size_t i = 0; i != m_rows; ++i)
	{
		std::transform(
			m_data[i].begin(),
			m_data[i].end(),
			result.m_data[i].begin(),
			[scalar](T val) { return val * scalar; }
        );
	}

	return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
	for (std::size_t i = 0; i != m_rows; ++i)
	{
		std::transform(
			m_data[i].begin(),
			m_data[i].end(),
			m_data[i].begin(),
			[scalar](T val) { return val * scalar; }
        );
	}

	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar)
{
	Matrix<T> result(m_rows, m_cols);

	for (std::size_t i = 0; i != m_rows; ++i)
	{
		std::transform(
			m_data[i].begin(),
			m_data[i].end(),
			result.m_data[i].begin(),
			[scalar, this](T val) { return val / (scalar + EPS); }
        );
	}

	return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{
	for (std::size_t i = 0; i != m_rows; ++i)
	{
		std::transform(
			m_data[i].begin(),
			m_data[i].end(),
			m_data[i].begin(),
			[scalar, this](T val) { return val / (scalar + EPS); }
        );
	}

	return *this;
}

template <typename T>
std::size_t Matrix<T>::num_rows() const
{
	return m_rows;
}

template <typename T>
std::size_t Matrix<T>::num_cols() const
{
	return m_cols;
}

} // end namespace cppmath