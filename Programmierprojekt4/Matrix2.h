#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include <exception>
#include <numeric>

#include "Vec.h"

template<typename T>
class Matrix
{
public:
	template<typename T>
	friend class Vec;

	Matrix<T>(); // Default Constructor
	Matrix<T>(const unsigned int &rows, const unsigned int &cols, const T &value); // User defined Constructor
	Matrix<T>(const std::vector<std::vector<T>> &data); // // User defined Constructor
	Matrix<T>(const unsigned int &rows, const unsigned int &cols); // User defined Constructor
	~Matrix<T>(); // User defined Destructor

	Matrix<T>(const Matrix<T> &matrixB); // Copy Constructor
	Matrix<T>& operator=(Matrix<T> matrixB); // Copy Assignment Operator

	void print_matrix() const;
	Matrix<T> transpose();

	Matrix<T> operator+(const Matrix<T> &matrixB);
	Matrix<T>& operator+=(const Matrix<T> &matrixB);

	Matrix<T> operator-(const Matrix<T> &matrixB);
	Matrix<T>& operator-=(const Matrix<T> &matrixB);

	Matrix<T> operator*(const Matrix<T> &matrixB);
	Matrix<T>& operator*=(const Matrix<T> &matrixB);

	Matrix<T> operator*(const T &scalar);
	Matrix<T>& operator*=(const T &scalar);

	Matrix<T> operator/(const T &scalar);
	Matrix<T>& operator/=(const T &scalar);

	Vec<T> operator*(const Vec<T> &vecB);

	unsigned int num_rows();
	unsigned int num_cols();

private:
	unsigned int m_rows;
	unsigned int m_cols;
	const double m_epsilon = 1e-6;
	std::vector<std::vector<T>> m_data;
};

template<typename T>
Matrix<T>::Matrix() :
	m_rows(0), 
	m_cols(0), 
	m_data(m_rows, std::vector<T>(m_cols, 0))
{

}

template<typename T>
Matrix<T>::Matrix(
	const unsigned int &rows, 
	const unsigned int &cols, 
	const T &value) :
		m_rows(rows), 
		m_cols(cols), 
		m_data(m_rows, std::vector<T>(m_cols, value))
{

}

template<typename T>
Matrix<T>::Matrix<T>(const std::vector<std::vector<T>> &data) :
	m_rows(data.size()),
	m_cols(m_rows ? data[0].size() : 0),
	m_data(data)
{

}

template<typename T>
Matrix<T>::Matrix(const unsigned int &rows, const unsigned int &cols) :
	m_rows(rows), 
	m_cols(cols), 
	m_data(m_rows, std::vector<T>(m_cols, 0))
{

}

template<typename T>
Matrix<T>::~Matrix()
{

}

// Copy Constructor
template<typename T>
Matrix<T>::Matrix<T>(const Matrix<T> &matrixB) :
	m_rows(matrixB.m_rows), 
	m_cols(matrixB.m_cols), 
	m_data(matrixB.m_data)
{

}

// Copy Assignment Operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T> matrixB)
{
	std::swap(this->m_rows, matrixB.m_rows);
	std::swap(this->m_cols, matrixB.m_cols);
	std::swap(this->m_data, matrixB.m_data);

	return *this;
}

template<typename T>
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

template<typename T>
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
template<typename T>
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

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix &matrixB)
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

template<typename T>
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

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix &matrixB)
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

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &matrixB)
{
	try
	{
		if (this->m_cols != matrixB.m_rows)
			throw(std::invalid_argument("Dimensions does not match!"));

		Matrix<T> result(m_rows, matrixB.m_cols);

		for (int i = 0; i != m_rows; ++i)
		{
			for (int j = 0; j != matrixB.m_cols; ++j)
			{
				for (int k = 0; k != matrixB.m_rows; ++k)
				{
					result.m_data[i][j] = result.m_data[i][j] + this->m_data[i][k] * matrixB.m_data[k][j];
				}
			}
		}

		return result;
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix &matrixB)
{
	return *this = (*this) * matrixB;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar)
{
	Matrix<T> result(m_rows, m_cols);

	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			result.m_data[i].begin(),
			[scalar](T val) {return val * scalar; });
	}

	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T &scalar)
{
	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			this->m_data[i].begin(),
			[scalar](T val) {return val * scalar; });
	}

	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar)
{
	Matrix<T> result(m_rows, m_cols);

	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			result.m_data[i].begin(),
			[scalar, this](T val) {return val / (scalar + this->m_epsilon); });
	}

	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(const T &scalar)
{
	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			this->m_data[i].begin(),
			[scalar, this](T val) {return val / (scalar + this->m_epsilon); });
	}

	return *this;
}

template<typename T>
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

template<typename T>
unsigned int Matrix<T>::num_rows()
{
	return m_rows;
}

template<typename T>
unsigned int Matrix<T>::num_cols()
{
	return m_cols;
}