#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include <exception>
#include <numeric>
#include <type_traits>
#include <omp.h>

#include "Vec.h"

constexpr int NUM_THREADS = 4;

namespace cppmath
{
template <typename T>
class Matrix
{
	static_assert(std::is_arithmetic<T>::value,
					"An specialization of the matrix class has to be of a floating type!");

public:
	template <typename T>
	friend class Vec;

	/***********************/
	/****  CONSTRUCTORS  ***/
	/***********************/
	Matrix<T>(const std::size_t &rows, const std::size_t &cols, const T &value); // User defined Constructor
	Matrix<T>(const std::vector<std::vector<T>> &data);							 // // User defined Constructor
	Matrix<T>(const std::size_t &rows, const std::size_t &cols);				 // User defined Constructor
	~Matrix<T>() noexcept = default;											 // Default Destructor

	/****************************/
	/* COPY/MOVE CONST./ASSIGN  */
	/****************************/
	Matrix<T>(const Matrix<T> &matrixB) = default;				  // Copy Constructor
	Matrix<T> &operator=(const Matrix<T> &matrixB) = default;	  // Copy Assignment Operator
	Matrix<T>(Matrix<T> &&matrixB) noexcept = default;			  // Move Constructor
	Matrix<T> &operator=(Matrix<T> &&matrixB) noexcept = default; // Move Assignment Operator

	/***********************/
	/*** MATH. OPERATORS ***/
	/***********************/
	Matrix<T> operator+(const Matrix<T> &matrixB);
	Matrix<T> &operator+=(const Matrix<T> &matrixB);
	Matrix<T> operator-(const Matrix<T> &matrixB);
	Matrix<T> &operator-=(const Matrix<T> &matrixB);
	Matrix<T> operator*(const Matrix<T> &matrixB);
	Matrix<T> &operator*=(const Matrix<T> &matrixB);
	void parallel_dot(const Matrix<T> &matrixA, const Matrix<T> &matrixB, Matrix<T> &result);
	void dot(const Matrix<T> &matrixA, const Matrix<T> &matrixB, Matrix<T> &result);
	Matrix<T> operator*(const T &scalar);
	Matrix<T> &operator*=(const T &scalar);
	Matrix<T> operator/(const T &scalar);
	Matrix<T> &operator/=(const T &scalar);
	Vec<T> operator*(const Vec<T> &vecB);
	Matrix<T> transpose();

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
	double m_epsilon = 1e-6;
	std::vector<std::vector<T>> m_data;
};
} // end namespace cppmath

namespace cppmath
{
/***********************/
/****  CONSTRUCTORS  ***/
/***********************/
template <typename T>
Matrix<T>::Matrix(
	const std::size_t &rows,
	const std::size_t &cols,
	const T &value) : m_rows(rows),
						m_cols(cols),
						m_data(m_rows, std::vector<T>(m_cols, value))
{
}

template <typename T>
Matrix<T>::Matrix(
	const std::vector<std::vector<T>> &data) : m_rows(data.size()),
												m_cols(m_rows ? data[0].size() : 0),
												m_data(data)
{
}

template <typename T>
Matrix<T>::Matrix(
	const std::size_t &rows,
	const std::size_t &cols) : m_rows(rows),
								m_cols(cols),
								m_data(m_rows, std::vector<T>(m_cols, 0))
{
}

/***********************/
/*** MATH. OPERATORS ***/
/***********************/
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &matrixB)
{
	try
	{
		if (this->m_rows != matrixB.m_rows)
			throw(std::invalid_argument("Number of Rows not equal!"));
		if (this->m_cols != matrixB.m_cols)
			throw(std::invalid_argument("Number of Cols not equal!"));

		Matrix<T> result(m_rows, m_cols);

		for (int i = 0; i != m_rows; ++i)
		{
			std::transform(
				this->m_data[i].begin(),
				this->m_data[i].end(),
				matrixB.m_data[i].begin(),
				result.m_data[i].begin(),
				std::plus<T>());
		}

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &matrixB)
{
	try
	{
		if (this->m_rows != matrixB.m_rows)
			throw(std::invalid_argument("Number of Rows not equal!"));
		if (this->m_cols != matrixB.m_cols)
			throw(std::invalid_argument("Number of Cols not equal!"));

		for (int i = 0; i != m_rows; ++i)
		{
			std::transform(
				this->m_data[i].begin(),
				this->m_data[i].end(),
				matrixB.m_data[i].begin(),
				this->m_data[i].begin(),
				std::plus<T>());
		}

		return *this;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &matrixB)
{
	try
	{
		if (this->m_rows != matrixB.m_rows)
			throw(std::invalid_argument("Number of Rows not equal!"));
		if (this->m_cols != matrixB.m_cols)
			throw(std::invalid_argument("Number of Cols not equal!"));

		Matrix<T> result(m_rows, m_cols);

		for (int i = 0; i != m_rows; ++i)
		{
			std::transform(
				this->m_data[i].begin(),
				this->m_data[i].end(),
				matrixB.m_data[i].begin(),
				result.m_data[i].begin(),
				std::minus<T>());
		}

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix &matrixB)
{
	try
	{
		if (this->m_rows != matrixB.m_rows)
			throw(std::invalid_argument("Number of Rows not equal!"));
		if (this->m_cols != matrixB.m_cols)
			throw(std::invalid_argument("Number of Cols not equal!"));

		for (int i = 0; i != m_rows; ++i)
		{
			std::transform(
				this->m_data[i].begin(),
				this->m_data[i].end(),
				matrixB.m_data[i].begin(),
				this->m_data[i].begin(),
				std::minus<T>());
		}

		return *this;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &matrixB)
{
	try
	{
		if (this->m_cols != matrixB.m_rows)
			throw(std::invalid_argument("Dimensions does not match!"));

		Matrix<T> result(m_rows, matrixB.m_cols);

		if (m_cols < 250 && m_rows < 250)
			dot(*this, matrixB, result);
		else
			parallel_dot(*this, matrixB, result);

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &matrixB)
{
	return *this = (*this) * matrixB;
}

template <typename T>
void Matrix<T>::parallel_dot(const Matrix<T> &matrixA, const Matrix<T> &matrixB, Matrix<T> &result)
{
	int i, j, k;

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
	int i, j, k;

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

	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			result.m_data[i].begin(),
			[scalar](T val) { return val * scalar; });
	}

	return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			this->m_data[i].begin(),
			[scalar](T val) { return val * scalar; });
	}

	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar)
{
	Matrix<T> result(m_rows, m_cols);

	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			result.m_data[i].begin(),
			[scalar, this](T val) { return val / (scalar + this->m_epsilon); });
	}

	return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{
	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			this->m_data[i].begin(),
			[scalar, this](T val) { return val / (scalar + this->m_epsilon); });
	}

	return *this;
}

template <typename T>
Vec<T> Matrix<T>::operator*(const Vec<T> &vecB)
{
	try
	{
		if (this->m_cols != vecB.m_length)
			throw(std::invalid_argument("Dimensions does not match!"));

		Vec<T> result(m_rows);

		for (int i = 0; i != m_rows; ++i)
		{
			result[i] = std::inner_product(
				this->m_data[i].begin(),
				this->m_data[i].end(),
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

	for (int i = 0; i != m_rows; ++i)
	{
		for (int j = 0; j != m_cols; ++j)
		{
			result.m_data[j][i] = this->m_data[i][j];
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
	for (int i = 0; i != m_rows; ++i)
	{
		for (int j = 0; j != m_cols; ++j)
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