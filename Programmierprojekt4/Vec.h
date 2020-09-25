#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include <exception>

#include "Types.h"
#include "Matrix.h"

namespace cppmath
{
template <typename T>
class Vec
{
	static_assert(std::is_floating_point<T>::value,
					"An specialization of the vector class has to be of a floating type!");

public:
	template <typename U>
	friend class Matrix;

	/***********************/
	/****  CONSTRUCTORS  ***/
	/***********************/
	Vec() = delete;
	Vec(std::size_t length, const T &value);
	Vec(std::size_t length);
	Vec(const std::vector<T> &data);
	~Vec() noexcept = default;

	/****************************/
	/* COPY/MOVE CONST./ASSIGN  */
	/****************************/
	Vec(const Vec &vectorB) = default;
	Vec &operator=(const Vec &vectorB) = default;
	Vec(Vec &&vectorB) noexcept = default;
	Vec &operator=(Vec &&vectorB) noexcept = default;

	/***********************/
	/**** ELEMENT ACCESS ***/
	/***********************/
	T &operator[](std::size_t i) { return m_data.at(i); };
	const T &operator[](std::size_t i) const { return m_data.at(i); };
	T &at(std::size_t i) { return m_data.at(i); };
	const T &at(std::size_t i) const { return m_data.at(i); };

	/***********************/
	/*** MATH. OPERATORS ***/
	/***********************/
	Vec operator+(const Vec &vectorB);
	Vec &operator+=(const Vec &vectorB);
	Vec operator-(const Vec &vectorB);
	Vec &operator-=(const Vec &vectorB);
	T operator*(const Vec &vectorB);
	Vec operator*(const T &scalar);
	Vec &operator*=(const T &scalar);
	Vec operator/(const T &scalar);
	Vec &operator/=(const T &scalar);

	/***********************/
	/*** HELPER FUNCTIONS **/
	/***********************/
	void print_vector() const;
	std::size_t length() const;

private:
	/***********************/
	/**** MEMBER VARS.  ****/
	/***********************/
	std::size_t m_length;
	std::vector<T> m_data;
};

/***********************/
/****  CONSTRUCTORS  ***/
/***********************/
template <typename T>
Vec<T>::Vec(std::size_t length, const T &value) :
	m_length(length),
	m_data(std::vector<T>(m_length, value))
{
}

template <typename T>
Vec<T>::Vec(std::size_t length) :
	m_length(length),
	m_data(std::vector<T>(length, 0))
{
}

template <typename T>
Vec<T>::Vec(const std::vector<T> &data) :
	m_length(data.size()),
	m_data(data)
{
}

/***********************/
/*** MATH. OPERATORS ***/
/***********************/

template <typename T>
Vec<T> Vec<T>::operator+(const Vec &vectorB)
{
	Vec<T> result(m_length);

	std::transform(
		m_data.begin(),
		m_data.end(),
		vectorB.m_data.begin(),
		result.m_data.begin(),
		std::plus<T>()
	);

	return result;
}

template <typename T>
Vec<T> &Vec<T>::operator+=(const Vec &vectorB)
{
	std::transform(
		m_data.begin(),
		m_data.end(),
		vectorB.m_data.begin(),
		m_data.begin(),
		std::plus<T>()
	);

	return *this;
}

template <typename T>
Vec<T> Vec<T>::operator-(const Vec &vectorB)
{
	Vec<T> result(m_length);

	std::transform(
		m_data.begin(),
		m_data.end(),
		vectorB.m_data.begin(),
		result.m_data.begin(),
		std::minus<T>()
	);

	return result;
}

template <typename T>
Vec<T> &Vec<T>::operator-=(const Vec &vectorB)
{
	std::transform(
		m_data.begin(),
		m_data.end(),
		vectorB.m_data.begin(),
		m_data.begin(),
		std::minus<T>()
	);

	return *this;
}

template <typename T>
T Vec<T>::operator*(const Vec &vectorB)
{
	T sum = 0;

	for (std::size_t i = 0; i != m_length; ++i)
	{
		sum += m_data[i] * vectorB.m_data[i];
	}

	return sum;
}

template <typename T>
Vec<T> Vec<T>::operator*(const T &scalar)
{
	Vec<T> result(m_length);

	std::transform(
		m_data.begin(),
		m_data.end(),
		result.m_data.begin(),
		[scalar](const T val) { return val * scalar; });

	return result;
}

template <typename T>
Vec<T> &Vec<T>::operator*=(const T &scalar)
{
	std::transform(
		m_data.begin(),
		m_data.end(),
		m_data.begin(),
		[scalar](const T val) { return val * scalar; }
	);

	return *this;
}

template <typename T>
Vec<T> Vec<T>::operator/(const T &scalar)
{
	Vec<T> result(m_length);

	std::transform(
		m_data.begin(),
		m_data.end(),
		result.m_data.begin(),
		[scalar](const T val) { return val / (scalar + EPS); }
	);

	return result;
}

template <typename T>
Vec<T> &Vec<T>::operator/=(const T &scalar)
{
	std::transform(
		m_data.begin(),
		m_data.end(),
		m_data.begin(),
		[scalar](const T val) { return val / (scalar + EPS); }
	);

	return *this;
}

/***********************/
/*** HELPER FUNCTIONS **/
/***********************/

template <typename T>
void Vec<T>::print_vector() const
{
	for (std::size_t i = 0; i != m_length; ++i)
	{
		std::cout << m_data[i] << std::endl;
	}

	std::cout << std::endl;
}

template <typename T>
std::size_t Vec<T>::length() const
{
	return m_length;
}

} // namespace cppmath