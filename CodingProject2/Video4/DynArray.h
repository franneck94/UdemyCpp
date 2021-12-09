#pragma once

#include <cstddef>

template <typename T>
class DynamicArray
{
public:
    // Constructor/Destructor
    DynamicArray();
    DynamicArray(const T &value, const std::size_t length);
    ~DynamicArray();

    // Data-manipulation methods
    void push_back(const T &value);
    void pop_back();

    // Operator overloading
    T &operator[](const std::size_t index);
    const T &operator[](const std::size_t index) const;

    // Helper methods
    std::size_t get_length() const;

private:
    std::size_t m_length;
    std::size_t m_capacity;
    T *m_data;
};

/**
 * @brief Create a dynamic array object
 */
template <typename T>
DynamicArray<T>::DynamicArray() : m_length(0), m_capacity(1), m_data(new T[m_capacity])
{
}

/**
 * @brief Create a dynamic array object
 *
 * @param value The fill value for the array.
 * @param length The length of the array.
 */
template <typename T>
DynamicArray<T>::DynamicArray(const T &value, const std::size_t length)
    : m_length(length), m_capacity(length > 0 ? length : 1), m_data(new T[m_capacity])
{
    for (std::size_t i = 0; i < length; i++)
    {
        m_data[i] = value;
    }
}

/**
 * @brief Destroys a dynamic array object
 */
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    if (m_data != nullptr)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}

/**
 * @brief Push backs the *value* at the end of the array.
 *
 * @param dynmaic_array The dynamic array.
 * @param value The value to append to the array.
 */
template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
    if (m_length == m_capacity)
    {
        m_capacity *= 2;

        T *temp = nullptr;
        temp = new T[m_capacity];

        for (std::size_t i = 0; i < m_length; i++)
        {
            temp[i] = m_data[i];
        }

        delete[] m_data;
        m_data = temp;
    }

    m_data[m_length] = value;
    m_length++;
}

/**
 * @brief Pop backs the value at the end of the vector.
 */
template <typename T>
void DynamicArray<T>::pop_back()
{
    if (m_length > 0)
    {
        m_length--;

        if (m_length < (m_capacity / 2))
        {
            m_capacity /= 2;

            T *temp = nullptr;
            temp = new T[m_capacity];

            for (std::size_t i = 0; i < m_length; i++)
            {
                temp[i] = m_data[i];
            }

            delete[] m_data;
            m_data = temp;
        }
    }
}

template <typename T>
T &DynamicArray<T>::operator[](const std::size_t index)
{
    return m_data[index];
}

template <typename T>
const T &DynamicArray<T>::operator[](const std::size_t index) const
{
    return m_data[index];
}

template <typename T>
std::size_t DynamicArray<T>::get_length() const
{
    return m_length;
}
