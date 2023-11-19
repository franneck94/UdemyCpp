#pragma once

#include <cstdlib>

template <typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(const T &value, const std::size_t length);
    ~DynamicArray();

    void push_back(const T &value);
    void pop_back();

    T &operator[](const std::size_t index);
    const T &operator[](const std::size_t index) const;

    std::size_t get_length() const;

private:
    std::size_t m_length;
    std::size_t m_capacity;
    T *m_data;
};

template <typename T>
DynamicArray<T>::DynamicArray()
{
}

template <typename T>
DynamicArray<T>::DynamicArray(const T &value, const std::size_t length)
{
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
}

template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
}

template <typename T>
void DynamicArray<T>::pop_back()
{
}

template <typename T>
T &DynamicArray<T>::operator[](const std::size_t index)
{
}

template <typename T>
const T &DynamicArray<T>::operator[](const std::size_t index) const
{
}

template <typename T>
std::size_t DynamicArray<T>::get_length() const
{
}
