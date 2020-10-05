#pragma once

#include <limits>
#include <stdexcept>
#include <algorithm>

#include "Iterators.h"

namespace learncpp
{

/**************************************/
/*                array               */
/**************************************/
template <class T, std::size_t N>
class array
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = RandomAcessIterator<value_type>;
    using const_iterator = RandomAcessIterator<const value_type>;
    using reverse_iterator = ReverseRandomAcessIterator<value_type>;
    using const_reverse_iterator = ReverseRandomAcessIterator<const value_type>;

public:
    /**************************************/
    /*          ELEMENT ACCESS            */
    /**************************************/
    [[nodiscard]] constexpr reference at(const size_type index)
    {
        if (index < N)
        {
            return m_data[index];
        }
        else
        {
            throw(std::out_of_range("Pos is not within the range of the container."));
        }
    }

    constexpr const_reference at(const size_type index) const
    {
        if (index < N)
        {
            return m_data[index];
        }
        else
        {
            throw(std::out_of_range("Pos is not within the range of the container."));
        }
    }

    [[nodiscard]] constexpr reference operator[](const size_type index)
    {
        return m_data[index];
    }

    constexpr const_reference operator[](const size_type index) const
    {
        return m_data[index];
    }

    [[nodiscard]] constexpr reference front()
    {
        return *begin();
    }

    [[nodiscard]] constexpr const_reference front() const
    {
        return *begin();
    }

    [[nodiscard]] constexpr reference back()
    {
        return *(end() - 1);
    }

    [[nodiscard]] constexpr const_reference back() const
    {
        return *(end() - 1);
    }

    [[nodiscard]] constexpr pointer data() noexcept
    {
        return m_data;
    }

    [[nodiscard]] constexpr const_pointer data() const noexcept
    {
        return m_data;
    }

    /**************************************/
    /*             ITERATORS              */
    /**************************************/
    [[nodiscard]] constexpr iterator begin() noexcept
    {
        return iterator(m_data);
    }

    [[nodiscard]] constexpr const_iterator begin() const noexcept
    {
        return const_iterator(m_data);
    }

    [[nodiscard]] constexpr const_iterator cbegin() const noexcept
    {
        return const_iterator(m_data);
    }

    [[nodiscard]] constexpr iterator end() noexcept
    {
        return iterator(m_data + N);
    }

    [[nodiscard]] constexpr const_iterator end() const noexcept
    {
        return const_iterator(m_data + N);
    }

    [[nodiscard]] constexpr const_iterator cend() const noexcept
    {
        return const_iterator(m_data + N);
    }

    [[nodiscard]] constexpr reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(m_data + N - 1);
    }

    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(m_data + N - 1);
    }

    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator(m_data + N - 1);
    }

    [[nodiscard]] constexpr reverse_iterator rend() noexcept
    {
        return reverse_iterator(m_data - 1);
    }

    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(m_data - 1);
    }

    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator(m_data - 1);
    }

    /**************************************/
    /*            CAPACITY                */
    /**************************************/
    [[nodiscard]] constexpr bool empty() const noexcept
    {
        return N > 0 ? false : true;
    }

    [[nodiscard]] constexpr size_type size() const noexcept
    {
        return N;
    }

    [[nodiscard]] constexpr size_type max_size() const noexcept
    {
        return std::numeric_limits<difference_type>::max();
    }

    /**************************************/
    /*             MODIFIERS              */
    /**************************************/
    constexpr void fill(const const_reference value)
    {
        std::fill(m_data, m_data + N, value);
    }

    constexpr void swap(array& other) noexcept
    {
        std::swap(m_data, other.m_data);
    }

public:
    value_type m_data[N];
};

template <class T, std::size_t N>
constexpr bool operator==(const array<T, N>& lhs, const array<T, N>& rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    
    for (int i = 0; i < lhs.size(); ++i)
    {
        if (lhs.at(i) != rhs.at(i))
        {
            return false;
        }
    }
    
    return true;
}

template <class T, std::size_t N>
constexpr bool operator!=(const array<T, N>& lhs, const array<T, N>& rhs)
{
    return !(lhs == rhs);
}

template <class T, std::size_t N>
constexpr bool operator<(const array<T, N>& lhs, const array<T, N>& rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, std::size_t N>
constexpr bool operator>(const array<T, N>& lhs, const array<T, N>& rhs)
{
    return rhs < lhs;
}

template <class T, std::size_t N>
constexpr bool operator<=(const array<T, N>& lhs, const array<T, N>& rhs)
{
    return !(rhs < lhs);
}

template <class T, std::size_t N>
constexpr bool operator>=(const array<T, N>& lhs, const array<T, N>& rhs)
{
    return !(lhs < rhs);
}

} // end namespace