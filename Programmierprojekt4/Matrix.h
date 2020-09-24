#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <exception>
#include <numeric>
#include <type_traits>
#include <omp.h>

#include "Types.h"
#include "Vec.h"

constexpr uint8_t NUM_THREADS = 4;

namespace cppmath
{

template <typename T>
class Matrix
{
	static_assert(std::is_floating_point<T>::value,
					"An specialization of the matrix class has to be of a floating type!");

public:
	template <typename U>
	friend class Vec;

	/***********************/
	/****  CONSTRUCTORS  ***/
	/***********************/
	Matrix() = delete;
	Matrix(std::size_t rows, std::size_t cols, const T &value);
	Matrix(std::size_t rows, std::size_t cols);
	~Matrix() noexcept = default;

	/****************************/
	/* COPY/MOVE CONST./ASSIGN  */
	/****************************/
	Matrix(const Matrix &other) = default;
	Matrix& operator=(const Matrix &other) = default;
	Matrix(Matrix &&other) noexcept = default;
	Matrix& operator=(Matrix &&other) noexcept = default;

	/***********************/
	/*** MATH. OPERATORS ***/
	/***********************/
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
	Vec<T> operator*(const Vec<T> &vecB);

	void parallel_dot(const Matrix &matrixA, const Matrix &matrixB, Matrix &result);
	void dot(const Matrix &matrixA, const Matrix &matrixB, Matrix &result);
	Matrix transpose();

	/***********************/
	/*** HELPER FUNCTIONS **/
	/***********************/
	void print_matrix() const;
	std::size_t num_rows() const;
	std::size_t num_cols() const;

private:
	/***********************/
	/**** MEMBER VARS.  ****/
	/***********************/
	std::size_t m_rows;
	std::size_t m_cols;
	std::vector<std::vector<T>> m_data;
};


/***********************/
/****  CONSTRUCTORS  ***/
/***********************/
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

/***********************/
/*** MATH. OPERATORS ***/
/***********************/
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs)
{
	try
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
			std::transform(
				m_data[i].begin(),
				m_data[i].end(),
				rhs.m_data[i].begin(),
				result.m_data[i].begin(),
				std::plus<T>()
			);
		}

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &rhs)
{
	try
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
			std::transform(
				m_data[i].begin(),
				m_data[i].end(),
				rhs.m_data[i].begin(),
				m_data[i].begin(),
				std::plus<T>()
			);
		}

		return *this;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &rhs)
{
	try
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
			std::transform(
				m_data[i].begin(),
				m_data[i].end(),
				rhs.m_data[i].begin(),
				result.m_data[i].begin(),
				std::minus<T>()
			);
		}

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix &rhs)
{
	try
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
			std::transform(
				m_data[i].begin(),
				m_data[i].end(),
				rhs.m_data[i].begin(),
				m_data[i].begin(),
				std::minus<T>()
			);
		}

		return *this;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs)
{
	try
	{
		if (m_cols != rhs.m_rows)
		{
			throw(std::invalid_argument("Dimensions does not match!"));
		}

		Matrix<T> result(m_rows, rhs.m_cols);

		if (m_cols < 250 && m_rows < 250)
		{
			dot(*this, rhs, result);
		}
		else
		{
			parallel_dot(*this, rhs, result);
		}

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &rhs)
{
	*this = (*this) * rhs;

	return *this;
}

template <typename T>
void Matrix<T>::parallel_dot(const Matrix<T> &matrixA, const Matrix<T> &matrixB, Matrix<T> &result)
{
	std::size_t i, j, k;

#pragma omp parallel for shared(result) private(i, j, k) num_threads(NUM_THREADS)
	for (i = 0; i < matrixA.m_rows; i++)
	{
		for (j = 0; j < matrixB.m_cols; j++)
		{
			for (k = 0; k < matrixB.m_rows; k++)
			{
				result.m_data[i][j] += matrixA.m_data[i][k] * matrixB.m_data[k][j];
			}
		}
	}
}

template <typename T>
void Matrix<T>::dot(const Matrix<T> &matrixA, const Matrix<T> &matrixB, Matrix<T> &result)
{
	std::size_t i, j, k;

	for (i = 0; i != matrixA.m_rows; ++i)
	{
		for (j = 0; j != matrixB.m_cols; ++j)
		{
			for (k = 0; k != matrixB.m_rows; ++k)
			{
				result.m_data[i][j] += matrixA.m_data[i][k] * matrixB.m_data[k][j];
			}
		}
	}
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
			[scalar, this](T val) { return val / (scalar + m_epsilon); }
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
			[scalar, this](T val) { return val / (scalar + m_epsilon); }
		);
	}

	return *this;
}

template <typename T>
Vec<T> Matrix<T>::operator*(const Vec<T> &vecB)
{
	try
	{
		if (m_cols != vecB.m_length)
		{
			throw(std::invalid_argument("Dimensions does not match!"));
		}

		Vec<T> result(m_rows);

		for (std::size_t i = 0; i != m_rows; ++i)
		{
			result[i] = std::inner_product(
				m_data[i].begin(),
				m_data[i].end(),
				vecB.m_data.begin(),
				0.0);
		}

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
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

/***********************/
/*** HELPER FUNCTIONS **/
/***********************/
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