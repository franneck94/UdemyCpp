#pragma once

#include <cstddef>

template <typename T> class DynamicArray
{
public:
    DynamicArray(const T &value, const std::size_t &length);

    const std::size_t get_length() const;

    void push_back(const T &value);
    void pop_back();

private:
    T *m_data;
    std::size_t m_length;
};

/**
 * @brief Create a dynamic array object
 *
 * @param value The fill value for the array.
 * @param length The length of the array.
 * @return DyanmicArray
 */
template <typename T> DynamicArray<T>::DynamicArray(const T &value, const std::size_t &length)
{
    m_length = length;
    m_data = new T[length];

    for (std::size_t i = 0; i < length; i++)
    {
        m_data[i] = value;
    }
}

/**
 * @brief Push backs the *value* at the end of the array.
 *
 * @param dynmaic_array The dynamic array.
 * @param value The value to append to the array.
 */
template <typename T> void DynamicArray<T>::push_back(const T &value)
{
    T *temp = nullptr;
    temp = new T[m_length + 1];

    for (std::size_t i = 0; i < m_length; i++)
    {
        temp[i] = m_data[i];
    }

    temp[m_length] = value;

    delete[] m_data;

    m_data = temp;
    m_length++;
}

/**
 * @brief Pop backs the value at the end of the vector.
 *
 * @param input_array The dynamic array.
 * @param size The size of the array.
 */
template <typename T> void DynamicArray<T>::pop_back()
{
    T *temp = nullptr;
    temp = new T[m_length - 1];

    for (std::size_t i = 0; i < m_length - 1; i++)
    {
        temp[i] = m_data[i];
    }

    delete[] m_data;

    m_data = temp;
    m_length--;
}
