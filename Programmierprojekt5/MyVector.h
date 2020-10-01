#pragma once

#include <limits>
#include <stdexcept>
#include <algorithm>

#include "MyIterators.h"

namespace cppmath
{

/**************************************/
/*                Vector              */
/**************************************/
template <class T, class Allocator = std::allocator<T>>
class Vector
{
public:
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = value_type* const;
    using iterator = RandomAcessIterator<value_type>;
    using const_iterator = RandomAcessIterator<const value_type>;
    using reverse_iterator = ReverseRandomAcessIterator<value_type>;
    using const_reverse_iterator = ReverseRandomAcessIterator<const value_type>;

    /**************************************/
    /*        SPECIAL MEMBER FUNCTIONS    */
    /**************************************/
public:
    constexpr Vector() noexcept :
        m_size(0), m_capacity(0), m_allocator(allocator_type()), m_data(nullptr)
    {
    }

    constexpr Vector(const size_type count, const_reference value, const allocator_type& alloc = allocator_type()) :
        m_size(count), m_capacity(count), m_allocator(alloc), m_data(m_allocator.allocate(m_capacity))
    {
        std::fill(m_data, m_data + m_size, value);
    }

    constexpr explicit Vector(size_type count, const allocator_type& alloc = allocator_type()) :
        m_size(count), m_capacity(count), m_allocator(alloc), m_data(m_allocator.allocate(m_capacity))
    {
        std::fill(m_data, m_data + m_size, value_type());
    }

    template <class InputIt >
    constexpr Vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) :
        m_size(std::distance(first, last)), m_capacity(m_size),
        m_allocator(alloc), m_data(m_allocator.allocate(m_capacity))
    {
        std::copy(first, last, m_data);
    }

    constexpr Vector(std::initializer_list<value_type> init, const allocator_type& alloc = allocator_type()) :
        m_size(init.size()), m_capacity(m_size), m_allocator(alloc), m_data(m_allocator.allocate(m_capacity))
    {
        std::copy(init.begin(), init.end(), m_data);
    }

    constexpr Vector(const Vector& other) :
        m_size(other.m_size), m_capacity(other.m_capacity), m_allocator(other.m_allocator), m_data( nullptr)
    {
        m_data = m_allocator.allocate(m_capacity);
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    
    constexpr Vector(Vector&& other) noexcept :
        m_size(std::move(other.m_size)), m_capacity(std::move(other.m_capacity)),
        m_allocator(std::move(other.m_allocator)), m_data(std::move(other.m_data))
    {
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }
    
    ~Vector() noexcept
    {
        if (m_data != nullptr)
        {
            for (size_type i = 0; i < m_size; ++i)
            {
                m_allocator.destroy(&m_data[i]);
            }

            m_allocator.deallocate(m_data, m_capacity);
            m_data = nullptr;
        }
    }

    constexpr Vector& operator=(const Vector& other)
    {
        if (this != &other)
        {
            if (m_size != other.m_size)
            {
                m_allocator.deallocate(m_data);

                m_size = other.m_size;
                m_capacity = other.m_capacity;

                if (other.m_size > 0)
                {
                    m_data = m_allocator.allocate(m_capacity);
                }
                else
                {
                    m_data = nullptr;
                }
            }

            std::copy(other.m_data, other.m_data + m_size, m_data);
        }
    }

    constexpr Vector& operator=(Vector&& other) noexcept
    {
        if (this != &other)
        {
            m_allocator.deallocate(m_data);

            m_size = std::move(other.m_size);
            m_capacity = std::move(other.m_capacity);
            m_data = std::move(other.m_data);

            other.m_size = 0;
            other.m_capacity = 0;
            other.m_data = nullptr;
        }

        return *this;
    }

    constexpr Vector& operator=(std::initializer_list<value_type> init)
    {
        if (m_size != init.size())
        {
            m_allocator.deallocate(m_data);

            m_size = init.size();
            m_capacity = init.size();

            if (init.size() > 0)
            {
                m_data = m_allocator.allocate(m_capacity);
            }
            else
            {
                m_data = nullptr;
            }
        }

        std::copy(init.begin(), init.end(), m_data);
    }

    constexpr void assign(size_type count, const_reference value)
    {
        std::fill(m_data, m_data + count, value);
    }

    template<class InputIt>
    constexpr void assign(InputIt first, InputIt last)
    {
        std::fill(first, last, m_data);
    }

    constexpr void assign(std::initializer_list<value_type> init)
    {
        std::fill(init.begin(), init.end(), m_data);
    }

    constexpr allocator_type get_allocator() const noexcept
    { 
        return m_allocator;
    }
    /**************************************/
    /*          ELEMENT ACCESS            */
    /**************************************/
    constexpr reference at(const size_type index)
    {
        if (index < m_size)
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
        if (index < m_size)
        {
            return m_data[index];
        }
        else
        {
            throw(std::out_of_range("Pos is not within the range of the container."));
        }
    }

    constexpr reference operator[](const size_type index)
    {
        return m_data[index];
    }

    constexpr const_reference operator[](const size_type index) const
    {
        return m_data[index];
    }

    constexpr reference front()
    {
        return *begin();
    }

    constexpr const_reference front() const
    {
        return *begin();
    }

    constexpr reference back()
    {
        return *(end() - 1);
    }

    constexpr const_reference back() const
    {
        return *(end() - 1);
    }

    constexpr pointer data() noexcept
    {
        return m_data;
    }

    constexpr const_pointer data() const noexcept
    {
        return m_data;
    }

    /**************************************/
    /*             ITERATORS              */
    /**************************************/
    constexpr iterator begin() noexcept
    {
        return iterator(m_data);
    }

    constexpr const_iterator begin() const noexcept
    {
        return const_iterator(m_data);
    }

    constexpr const_iterator cbegin() const noexcept
    {
        return const_iterator(m_data);
    }

    constexpr iterator end() noexcept
    {
        return iterator(m_data + m_size);
    }

    constexpr const_iterator end() const noexcept
    {
        return const_iterator(m_data + m_size);
    }

    constexpr const_iterator cend() const noexcept
    {
        return const_iterator(m_data + m_size);
    }

    constexpr reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(m_data + m_size - 1);
    }

    constexpr const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(m_data + m_size - 1);
    }

    constexpr const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator(m_data + m_size - 1);
    }

    constexpr reverse_iterator rend() noexcept
    {
        return reverse_iterator(m_data - 1);
    }

    constexpr const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(m_data - 1);
    }

    constexpr const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator(m_data - 1);
    }

    /**************************************/
    /*            CAPACITY                */
    /**************************************/
    constexpr bool empty() const noexcept
    {
        return m_size > 0 ? true : false;
    }

    constexpr size_type size() const noexcept
    {
        return m_size;
    }

    constexpr size_type max_size() const noexcept
    {
        return std::numeric_limits<difference_type>::max();
    }

    constexpr void reserve(const size_type new_capacity)
    {
        if (new_capacity > max_size())
        {
            throw new std::length_error("Capacity cannot be larger than max size!");
        }
        
        if (new_capacity > m_capacity)
        {
            reallocate(new_capacity);
        }
        
        m_capacity = new_capacity;
    }

    constexpr size_type capacity() const noexcept
    {
        return m_capacity;
    }

    constexpr void shrink_to_fit()
    {
        if (m_size != m_capacity)
        {
            reallocate(m_size);
        }
    }

    /**************************************/
    /*             MODIFIERS              */
    /**************************************/
    constexpr void clear() noexcept
    {
        m_size = 0;
    }

    constexpr iterator insert(const_iterator pos, const_reference value)
    {
        return insert(pos, 1, value);
    }

    constexpr iterator insert(const_iterator pos, value_type&& value)
    {
        difference_type index = pos - begin();
        
        if (index > m_size)
        {
            throw new std::out_of_range("Insert index is out of range");
        }

        if (m_size == m_capacity)
        {
            reallocate(m_size + 1);
        }

        iterator it = &m_data[index];

        std::move(it, end(), it + 1);
        *it = std::move(value);

        m_size += 1;

        return it;
    }

    constexpr iterator insert(const_iterator pos, size_type count, const_reference value)
    {
        const difference_type index = pos - begin();
        
        if (index > m_size)
        {
            throw new std::out_of_range("Insert index is out of range");
        }

        if (m_size + count > m_capacity)
        {
            reallocate(m_size + count);
        }

        iterator it = &m_data[index];

        std::move(it, end(), it + count);
        std::fill_n(it, count, value);

        m_size += count;

        return it;
    }

    template<class InputIt>
    constexpr iterator insert(const_iterator pos, InputIt first, InputIt last)
    {
        const difference_type count = last - first;
        const difference_type index = pos - begin();
        
        if (m_size + count > m_capacity)
        {
            reallocate(m_size + count);
        }
        
        iterator it = &m_data[index];
        std::move(it, end(), it + count);
        std::copy(first, last, it);
        
        m_size += count;
        
        return it;
    }

    constexpr iterator insert(const_iterator pos, std::initializer_list<value_type> ilist)
    {
        const difference_type count = ilist.m_size;
        const difference_type index = pos - begin();
        
        if (m_size + count > m_capacity)
        {
            reallocate(m_size + count);
        }
        
        iterator it = &m_data[index];
        std::move(it, end(), it + count);
        std::copy(ilist.begin(), ilist.end(), it);
        
        m_size += count;
        
        return it;
    }

    template<class... Args>
    constexpr iterator emplace(const_iterator pos, Args&&... args)
    {
        const difference_type index = pos - begin();
        
        if (index > m_size)
        {
            throw new std::out_of_range("Insert index is out of range");
        }
        
        if (m_size == m_capacity)
        {
            reallocate(m_capacity + 1);
        }
        
        iterator it = &m_data[index];
        
        std::move(it, end(), it + 1);
        m_allocator.construct(it, args...);
        
        m_size += 1;
        
        return it;
    }

    constexpr iterator erase(const_iterator pos)
    {
        const difference_type index = pos - begin();
        m_allocator.destroy(&m_data[index]);
        
        for (auto i = index; i < m_size - 1; ++i)
        {
            m_allocator.destroy(&m_data[i + 1]);
            m_allocator.construct(&m_data[i], *(m_data + i + 1));
        }
        
        m_size--;
        iterator it = &m_data[index];
        
        return it;
    }

    constexpr iterator erase(const_iterator first, const_iterator last)
    {
        const difference_type startIndex = first - begin();
        const difference_type endIndex = last - begin();
        
        for (difference_type i = 0; i < endIndex - startIndex; ++i)
        {
            m_allocator.destroy(&m_data[startIndex + i]);
            m_allocator.construct(&m_data[startIndex + i], m_data[endIndex + i]);
        }
        
        m_size -= endIndex - startIndex;
        iterator it = &m_data[startIndex];
        
        return it;
    }
    
    constexpr void push_back(const_reference value)
    {
        if (m_size == m_capacity)
        {
            reallocate(m_size + 1);
        }

        m_data[m_size] = value;
        m_size += 1;
    }

    constexpr void push_back(value_type&& value)
    {
        emplace(end(), std::move(value));
    }

    template<class... Args>
    constexpr reference emplace_back(Args&&... args)
    {
        emplace(end(), std::forward<Args>(args)...);
    }

    constexpr void pop_back()
    {
        if (m_size > 0)
        {
            m_size--;
        }
    }

    constexpr void resize(size_type count)
    {
        resize(count, value_type());
    }

    constexpr void resize(size_type count, const_reference value)
    {
        if (m_capacity < count)
        {
            reallocate(count);
            std::fill(m_data + m_size, m_data + m_capacity, value);
        }
        else // capacity is large enough
        {
            std::fill(m_data + m_size, m_data + m_capacity, value);
        }

        m_size = count;
    }

    constexpr void swap(Vector& other) noexcept
    {
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        std::swap(m_allocator, other.m_allocator);
        std::swap(m_data, other.m_data);
    }

private:
    size_type m_size;
    size_type m_capacity;
    allocator_type m_allocator;
    pointer m_data;

private:
    constexpr size_type calculate_grwoth(size_type new_size) const
    {
        const size_type geometric = m_capacity * 1.5;

        if (geometric > max_size() || new_size > max_size())
        {
            throw new std::length_error("Capacity cannot be larger than max size!");
        }

        if (geometric < new_size)
        {
            return new_size;
        }

        return geometric;
    }

    constexpr void reallocate(size_type new_size)
    {
        const size_type new_capacity = calculate_grwoth(new_size);
        pointer new_data = m_allocator.allocate(new_capacity);

        for (size_type i = 0; i < m_size; ++i)
        {
            m_allocator.construct(&new_data[i], std::move(new_data[i]));
            m_allocator.destroy(&m_data[i]);
        }
        m_allocator.deallocate(m_data, m_capacity);

        m_data = new_data;
        m_capacity = new_capacity;
    }
};

template <class T, class Allocator>
constexpr bool operator==(const Vector<T, Allocator>& lhs, const Vector<T, Allocator>& rhs)
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

template <class T, class Allocator>
constexpr bool operator!=(const Vector<T, Allocator>& lhs, const Vector<T, Allocator>& rhs)
{
    return !(lhs == rhs);
}

template <class T, class Allocator>
constexpr bool operator<(const Vector<T, Allocator>& lhs, const Vector<T, Allocator>& rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Allocator>
constexpr bool operator>(const Vector<T, Allocator>& lhs, const Vector<T, Allocator>& rhs)
{
    return rhs < lhs;
}

template <class T, class Allocator>
constexpr bool operator<=(const Vector<T, Allocator>& lhs, const Vector<T, Allocator>& rhs)
{
    return !(rhs < lhs);
}

template <class T, class Allocator>
constexpr bool operator>=(const Vector<T, Allocator>& lhs, const Vector<T, Allocator>& rhs)
{
    return !(lhs < rhs);
}

} // end namespace