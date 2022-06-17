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
