#pragma once

#include <iterator>

namespace learncpp
{

template <class T>
class RandomAcessIterator
{
public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::random_access_iterator_tag;

public:
    constexpr RandomAcessIterator(value_type* ptr) :
        m_ptr(ptr)
    {
    }

    constexpr RandomAcessIterator& operator++()
    {
        m_ptr++;
        return *this;
    }

    constexpr RandomAcessIterator operator++(int)
    {
        RandomAcessIterator tmp = *this;
        ++m_ptr;
        return tmp;
    }

    constexpr RandomAcessIterator& operator--()
    {
        m_ptr--;
        return *this;
    }

    constexpr RandomAcessIterator operator--(int)
    {
        RandomAcessIterator tmp = *this;
        --m_ptr;
        return tmp;
    }

    constexpr RandomAcessIterator operator+(difference_type n) const
    {
        return RandomAcessIterator(m_ptr + n);
    }

    constexpr RandomAcessIterator& operator+=(difference_type n)
    {
        m_ptr += n;

        return *this;
    }

    constexpr RandomAcessIterator operator-(difference_type n) const
    {
        return RandomAcessIterator(m_ptr - n);
    }

    constexpr RandomAcessIterator& operator-=(difference_type n)
    {
        m_ptr -= n;

        return *this;
    }

    constexpr difference_type operator-(const RandomAcessIterator& other) const
    {
        return std::distance(other.m_ptr, m_ptr);
    }

    constexpr reference operator[](difference_type index)
    {
        return *(m_ptr + index);
    }

    constexpr pointer operator->()
    {
        return m_ptr;
    }

    constexpr reference operator*()
    {
        return *m_ptr;
    }

    constexpr bool operator==(const RandomAcessIterator& other) const
    {
        return m_ptr == other.m_ptr;
    }

    constexpr bool operator!=(const RandomAcessIterator& other) const
    {
        return m_ptr != other.m_ptr;
    }

protected:
    value_type* m_ptr;
};

template <class T>
class ReverseRandomAcessIterator
{
public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::random_access_iterator_tag;

public:
    constexpr ReverseRandomAcessIterator(value_type* ptr) :
        m_ptr(ptr)
    {
    }

    constexpr ReverseRandomAcessIterator& operator++()
    {
        m_ptr--;
        return *this;
    }

    constexpr ReverseRandomAcessIterator operator++(int)
    {
        ReverseRandomAcessIterator tmp = *this;
        --m_ptr;
        return tmp;
    }

    constexpr ReverseRandomAcessIterator& operator--()
    {
        m_ptr++;
        return *this;
    }

    constexpr ReverseRandomAcessIterator operator--(int)
    {
        ReverseRandomAcessIterator tmp = *this;
        ++m_ptr;
        return tmp;
    }

    constexpr ReverseRandomAcessIterator operator+(difference_type n) const
    {
        return ReverseRandomAcessIterator(m_ptr - n);
    }

    constexpr ReverseRandomAcessIterator& operator+=(difference_type n)
    {
        m_ptr -= n;

        return *this;
    }

    constexpr ReverseRandomAcessIterator operator-(difference_type n) const
    {
        return ReverseRandomAcessIterator(m_ptr + n);
    }

    constexpr ReverseRandomAcessIterator& operator-=(difference_type n)
    {
        m_ptr += n;

        return *this;
    }

    constexpr difference_type operator-(const ReverseRandomAcessIterator& other) const
    {
        return std::distance(m_ptr, other.m_ptr);
    }

    constexpr reference operator[](difference_type index)
    {
        return *(m_ptr - index);
    }

    constexpr pointer operator->()
    {
        return m_ptr;
    }

    constexpr reference operator*()
    {
        return *m_ptr;
    }

    constexpr bool operator==(const ReverseRandomAcessIterator& other) const
    {
        return m_ptr == other.m_ptr;
    }

    constexpr bool operator!=(const ReverseRandomAcessIterator& other) const
    {
        return m_ptr != other.m_ptr;
    }

protected:
    value_type* m_ptr;
};

} // end namespace