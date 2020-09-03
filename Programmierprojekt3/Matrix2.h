#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <limits>

template <typename T>
class Matrix
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

template <typename T>
Matrix<T>::Matrix(const unsigned int &rows, const unsigned int &cols, const T &value) : m_rows(rows), m_cols(cols), m_value(value), m_data(m_rows, vector<T>(m_cols, m_value)),
																						m_epsilon(std::numeric_limits<T>::min())
{
	std::cout << "Created Matrix: " << &this->m_data << std::endl;
}

template <typename T>
Matrix<T>::Matrix(const unsigned int &rows, const unsigned int &cols) : m_rows(rows), m_cols(cols), m_value(0.0), m_data(m_rows, vector<T>(m_cols, 0)),
																		m_epsilon(std::numeric_limits<T>::min())
{
	std::cout << "Created Matrix: " << &this->m_data << std::endl;
}

template <typename T>
Matrix<T>::~Matrix()
{
	std::cout << "Deleted Matrix: " << &this->m_data << std::endl;
}

template <typename T>
void Matrix<T>::print_matrix() const
{
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrixB)
{
}

template <typename T>
Matrix<T> Matrix<T>::transpose()
{
}

template <typename T>
Matrix Matrix<T>::operator+(const Matrix &matrixB)
{
}

template <typename T>
Matrix &Matrix<T>::operator+=(const Matrix &matrixB)
{
}

template <typename T>
Matrix Matrix<T>::operator-(const Matrix &matrixB)
{
}

template <typename T>
Matrix &Matrix<T>::operator-=(const Matrix &matrixB)
{
}

template <typename T>
Matrix Matrix<T>::operator*(const Matrix &matrixB)
{
}

template <typename T>
Matrix &Matrix<T>::operator*=(const Matrix &matrixB)
{
}

template <typename T>
Matrix Matrix<T>::operator*(const double &scalar)
{
}

template <typename T>
Matrix &Matrix<T>::operator*=(const double &scalar)
{
}

template <typename T>
Matrix Matrix<T>::operator/(const double &scalar)
{
}

template <typename T>
Matrix &Matrix<T>::operator/=(const double &scalar)
{
}

template <typename T>
unsigned int Matrix<T>::num_rows()
{
}

template <typename T>
unsigned int Matrix<T>::num_cols()
{
}