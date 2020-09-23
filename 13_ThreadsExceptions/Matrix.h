#pragma once

#include <algorithm>
#include <exception>
#include <functional>
#include <limits>
#include <vector>


template <typename T> class Matrix
{
  public:
    Matrix<T>();                                                                   // Default Constructor
    Matrix<T>(const unsigned int &rows, const unsigned int &cols, const T &value); // User defined Constructor
    Matrix<T>(const unsigned int &rows, const unsigned int &cols);                 // User defined Constructor
    ~Matrix<T>();                                                                  // User defined Destructor

    Matrix<T>(const Matrix<T> &matrixB);     // Copy Constructor
    Matrix<T> &operator=(Matrix<T> matrixB); // Copy Assignment Operator

    void print_matrix() const;
    Matrix<T> transpose();

    Matrix operator+(const Matrix &matrixB);
    Matrix &operator+=(const Matrix &matrixB);

    Matrix operator-(const Matrix &matrixB);
    Matrix &operator-=(const Matrix &matrixB);

    Matrix operator*(const Matrix &matrixB);
    Matrix &operator*=(const Matrix &matrixB);

    Matrix operator*(const T &scalar);
    Matrix &operator*=(const T &scalar);

    Matrix operator/(const T &scalar);
    Matrix &operator/=(const T &scalar);

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
Matrix<T>::Matrix()
    : m_rows(0), m_cols(0), m_value(0.0), m_data(m_rows, std::vector<T>(m_cols, m_value)), m_epsilon(1e-6)
{
}

template <typename T>
Matrix<T>::Matrix(const unsigned int &rows, const unsigned int &cols, const T &value)
    : m_rows(rows), m_cols(cols), m_value(value), m_data(m_rows, std::vector<T>(m_cols, m_value)), m_epsilon(1e-6)
{
}

template <typename T>
Matrix<T>::Matrix(const unsigned int &rows, const unsigned int &cols)
    : m_rows(rows), m_cols(cols), m_value(0.0), m_data(m_rows, std::vector<T>(m_cols, 0)), m_epsilon(1e-6)
{
}

template <typename T> Matrix<T>::~Matrix()
{
}

// Copy Constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T> &matrixB)
    : m_rows(matrixB.m_rows), m_cols(matrixB.m_cols), m_data(matrixB.m_data), m_epsilon(matrixB.m_epsilon),
      m_value(matrixB.m_value)
{
}

// Copy Assignment Operator
template <typename T> Matrix<T> &Matrix<T>::operator=(Matrix<T> matrixB)
{
    std::swap(this->m_rows, matrixB.m_rows);
    std::swap(this->m_cols, matrixB.m_cols);
    std::swap(this->m_data, matrixB.m_data);

    return *this;
}

template <typename T> void Matrix<T>::print_matrix() const
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

template <typename T> Matrix<T> Matrix<T>::transpose()
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
template <typename T> Matrix<T> Matrix<T>::operator+(const Matrix &matrixB)
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
            std::transform(this->m_data[i].begin(), this->m_data[i].end(), matrixB.m_data[i].begin(),
                           result.m_data[i].begin(), std::plus<T>());
        }

        return result;
    }
    catch (std::invalid_argument &err)
    {
        std::cerr << err.what() << std::endl;
    }
}

template <typename T> Matrix<T> &Matrix<T>::operator+=(const Matrix &matrixB)
{
    for (int i = 0; i != m_rows; ++i)
    {
        std::transform(this->m_data[i].begin(), this->m_data[i].end(), matrixB.m_data[i].begin(),
                       this->m_data[i].begin(), std::plus<T>());
    }

    return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator-(const Matrix &matrixB)
{
    Matrix<T> result(m_rows, m_cols);

    for (int i = 0; i != m_rows; ++i)
    {
        std::transform(this->m_data[i].begin(), this->m_data[i].end(), matrixB.m_data[i].begin(),
                       result.m_data[i].begin(), std::minus<T>());
    }

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator-=(const Matrix &matrixB)
{
    for (int i = 0; i != m_rows; ++i)
    {
        std::transform(this->m_data[i].begin(), this->m_data[i].end(), matrixB.m_data[i].begin(),
                       this->m_data[i].begin(), std::minus<T>());
    }

    return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const Matrix &matrixB)
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

template <typename T> Matrix<T> &Matrix<T>::operator*=(const Matrix &matrixB)
{
    return *this = (*this) * matrixB;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const T &scalar)
{
    Matrix<T> result(m_rows, m_cols);

    for (int i = 0; i != m_rows; ++i)
    {
        std::transform(this->m_data[i].begin(), this->m_data[i].end(), result.m_data[i].begin(),
                       [scalar](T val) { return val * scalar; });
    }

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
    for (int i = 0; i != m_rows; ++i)
    {
        std::transform(this->m_data[i].begin(), this->m_data[i].end(), this->m_data[i].begin(),
                       [scalar](T val) { return val * scalar; });
    }

    return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator/(const T &scalar)
{
    Matrix<T> result(m_rows, m_cols);

    for (int i = 0; i != m_rows; ++i)
    {
        std::transform(this->m_data[i].begin(), this->m_data[i].end(), result.m_data[i].begin(),
                       [scalar, this](T val) { return val / (scalar + this->m_epsilon); });
    }

    return result;
}

template <typename T> Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{
    for (int i = 0; i != m_rows; ++i)
    {
        std::transform(this->m_data[i].begin(), this->m_data[i].end(), this->m_data[i].begin(),
                       [scalar, this](T val) { return val / (scalar + this->m_epsilon); });
    }

    return *this;
}

template <typename T> unsigned int Matrix<T>::num_rows()
{
    return m_rows;
}

template <typename T> unsigned int Matrix<T>::num_cols()
{
    return m_cols;
}