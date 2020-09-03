#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include <exception>

#include "Matrix7.h"

namespace cppmath
{
	template <typename T>
	class Vector
	{
		static_assert(std::is_floating_point<T>::value,
					  "An specialization of the vector class has to be of a floating type!");

	public:
		template <typename T>
		friend class Matrix;

		/***********************/
		/****  CONSTRUCTORS  ***/
		/***********************/
		Vector<T>(const std::size_t &length, const T &value); // User defined Constructor
		Vector<T>(const std::vector<T> &data);				  // User defined Constructor
		Vector<T>(const std::size_t &length);				  // User defined Constructor
		~Vector<T>() noexcept = default;					  // Default Destructor

		/****************************/
		/* COPY/MOVE CONST./ASSIGN  */
		/****************************/
		Vector<T>(const Vector<T> &vectorB) = default;				  // Copy Constructor
		Vector<T> &operator=(const Vector<T> &vectorB) = default;	  // Copy Assignment Operator
		Vector<T>(Vector<T> &&vectorB) noexcept = default;			  // Move Constructor
		Vector<T> &operator=(Vector<T> &&vectorB) noexcept = default; // Move Assignment Operator

		/***********************/
		/**** ELEMENT ACCESS ***/
		/***********************/
		T &operator[](const std::size_t &i) { return m_data.at(i); };
		const T &operator[](const std::size_t &i) const { return m_data.at(i); };
		T &at(const std::size_t &i) { return m_data.at(i); };
		const T &at(const std::size_t &i) const { return m_data.at(i); };

		/***********************/
		/*** MATH. OPERATORS ***/
		/***********************/
		Vector<T> operator+(const Vector &vectorB);
		Vector<T> &operator+=(const Vector &vectorB);
		Vector<T> operator-(const Vector &vectorB);
		Vector<T> &operator-=(const Vector &vectorB);
		T operator*(const Vector &vectorB);
		Vector<T> operator*(const T &scalar);
		Vector<T> &operator*=(const T &scalar);
		Vector<T> operator/(const T &scalar);
		Vector<T> &operator/=(const T &scalar);

		/***********************/
		/*** HELPER FUNCTIONS **/
		/***********************/
		void print_vector() const;
		const std::size_t length() const;

	private:
		/***********************/
		/**** MEMBER VARS.  ****/
		/***********************/
		std::size_t m_length = 0;
		double m_epsilon = 1e-6;
		std::vector<T> m_data;
	};
} // end namespace cppmath

namespace cppmath
{
	/***********************/
	/****  CONSTRUCTORS  ***/
	/***********************/
	template <typename T>
	Vector<T>::Vector(
		const std::size_t &length,
		const T &value) : m_length(length),
						  m_data(std::vector<T>(m_length, value))
	{
	}

	template <typename T>
	Vector<T>::Vector(
		const std::vector<T> &data) : m_length(data.size()),
									  m_data(data)
	{
	}

	template <typename T>
	Vector<T>::Vector(
		const std::size_t &length) : m_length(length),
									 m_data(std::vector<T>(length, 0))
	{
	}

	/***********************/
	/*** MATH. OPERATORS ***/
	/***********************/

	template <typename T>
	Vector<T> Vector<T>::operator+(
		const Vector &vectorB)
	{
		Vector<T> result(m_length);

		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			vectorB.m_data.begin(),
			result.m_data.begin(),
			std::plus<T>());

		return result;
	}

	template <typename T>
	Vector<T> &Vector<T>::operator+=(
		const Vector &vectorB)
	{
		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			vectorB.m_data.begin(),
			this->m_data.begin(),
			std::plus<T>());

		return *this;
	}

	template <typename T>
	Vector<T> Vector<T>::operator-(
		const Vector &vectorB)
	{
		Vector<T> result(m_length);

		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			vectorB.m_data.begin(),
			result.m_data.begin(),
			std::minus<T>());

		return result;
	}

	template <typename T>
	Vector<T> &Vector<T>::operator-=(
		const Vector &vectorB)
	{
		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			vectorB.m_data.begin(),
			this->m_data.begin(),
			std::minus<T>());

		return *this;
	}

	template <typename T>
	T Vector<T>::operator*(
		const Vector &vectorB)
	{
		T sum = 0;

		for (std::size_t i = 0; i != m_length; ++i)
		{
			sum += this->m_data[i] * vectorB.m_data[i];
		}

		return sum;
	}

	template <typename T>
	Vector<T> Vector<T>::operator*(
		const T &scalar)
	{
		Vector<T> result(m_length);

		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			result.m_data.begin(),
			[scalar](T val) { return val * scalar; });

		return result;
	}

	template <typename T>
	Vector<T> &Vector<T>::operator*=(
		const T &scalar)
	{
		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			this->m_data.begin(),
			[scalar](T val) { return val * scalar; });

		return *this;
	}

	template <typename T>
	Vector<T> Vector<T>::operator/(
		const T &scalar)
	{
		Vector<T> result(m_length);

		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			result.m_data.begin(),
			[scalar, this](T val) { return val / (scalar + this->m_epsilon); });

		return result;
	}

	template <typename T>
	Vector<T> &Vector<T>::operator/=(
		const T &scalar)
	{
		std::transform(
			this->m_data.begin(),
			this->m_data.end(),
			this->m_data.begin(),
			[scalar, this](T val) { return val / (scalar + this->m_epsilon); });

		return *this;
	}

	/***********************/
	/*** HELPER FUNCTIONS **/
	/***********************/

	template <typename T>
	void Vector<T>::print_vector() const
	{
		for (std::size_t i = 0; i != m_length; ++i)
		{
			std::cout << m_data[i] << std::endl;
		}

		std::cout << std::endl;
	}

	template <typename T>
	const std::size_t Vector<T>::length() const
	{
		return m_length;
	}
} // end namespace cppmath