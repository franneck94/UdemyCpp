#pragma once

#include <cstddef>
#include <utility>
#include <limits>
#include <stdexcept>
#include <algorithm>

/**************************************/
/*      VECTOR ITERATOR TRAITS        */
/**************************************/
template<class DynamicArray>
struct iterator_traits
{
    using value_type = typename DynamicArray::value_type;
    using difference_type = typename DynamicArray::difference_type;
    using reference = typename DynamicArray::reference;
    using pointer = typename DynamicArray::pointer;
};

template<class DynamicArray>
struct const_iterator_traits
{
    using value_type = typename DynamicArray::value_type;
    using difference_type = typename DynamicArray::difference_type;
    using reference = typename DynamicArray::const_reference;
    using pointer = typename DynamicArray::const_pointer;
};

/**************************************/
/*          VECTOR ITERATOR           */
/**************************************/
template <class iterator_traits>
class RandomAcessIterator
{
public:
    using value_type = typename iterator_traits::value_type;
    using difference_type = typename iterator_traits::difference_type;
    using reference = typename iterator_traits::reference;
    using pointer = typename iterator_traits::pointer;


public:
    RandomAcessIterator(pointer ptr) : 
        m_ptr(ptr)
    {
    }

    RandomAcessIterator& operator++()
    {
        m_ptr++;
        return *this;
    }

    RandomAcessIterator& operator++(int)
    {
        RandomAcessIterator it = *this;
        ++(*this);
        return it;
    }

    RandomAcessIterator& operator--()
    {
        m_ptr--;
        return *this;
    }

    RandomAcessIterator& operator--(int)
    {
        RandomAcessIterator it = *this;
        --(*this);
        return it;
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

    constexpr bool operator==(const RandomAcessIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    constexpr bool operator!=(const RandomAcessIterator &other) const
    {
        return m_ptr != other.m_ptr;
    }

private:
    pointer m_ptr;
};

template <class iterator_traits>
class ReverseRandomAcessIterator
{
public:
    using value_type = typename iterator_traits::value_type;
    using difference_type = typename iterator_traits::difference_type;
    using reference = typename iterator_traits::reference;
    using pointer = typename iterator_traits::pointer;


public:
    ReverseRandomAcessIterator(pointer ptr) : 
        m_ptr(ptr)
    {
    }

    ReverseRandomAcessIterator& operator++()
    {
        m_ptr--;
        return *this;
    }

    ReverseRandomAcessIterator& operator++(int)
    {
        ReverseRandomAcessIterator it = *this;
        --(*this);
        return it;
    }

    ReverseRandomAcessIterator& operator--()
    {
        m_ptr++;
        return *this;
    }

    ReverseRandomAcessIterator& operator--(int)
    {
        ReverseRandomAcessIterator it = *this;
        ++(*this);
        return it;
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

    constexpr bool operator==(const ReverseRandomAcessIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    constexpr bool operator!=(const ReverseRandomAcessIterator &other) const
    {
        return m_ptr != other.m_ptr;
    }

private:
    pointer m_ptr;
};

/**************************************/
/*            VECTOR CLASS            */
/**************************************/
template <typename T>
class DynamicArray
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer = T* const;
protected:
    using iterator_trait = iterator_traits<DynamicArray<T>>;
    using const_iterator_trait = const_iterator_traits<DynamicArray<T>>;
public:
    using iterator = RandomAcessIterator<iterator_trait>;
    using const_iterator = RandomAcessIterator<const_iterator_trait>;
    using reverse_iterator = ReverseRandomAcessIterator<iterator_trait>;
    using const_reverse_iterator = ReverseRandomAcessIterator<const_iterator_trait>;

    /**************************************/
    /*        SPECIAL MEMBER FUNCTIONS    */
    /**************************************/
public:
    /**
     * @brief Create an empty dynamic array object
     */
    DynamicArray() : 
        m_size(0), m_capacity(0), m_data(nullptr)
    { 
    }

    /**
     * @brief Create a dynamic array object
     */
    DynamicArray(const size_type length, const_reference value) :
        m_size(length), m_capacity(length), m_data(new value_type[length])
    {
        std::fill(m_data, m_data + m_size, value);
    }

    /**
     * @brief Destroys a dynamic array object
     */
    ~DynamicArray() noexcept
    {
        if (m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    /**
     * @brief Copy constructor.
     * 
     * @param other other DynmaicArray
     */
    DynamicArray(const DynamicArray &other) :
        m_size(other.m_size),
        m_capacity(other.m_capacity),
        m_data(other.m_size > 0 ? new value_type[other.m_size] : nullptr)
    {
        std::copy(m_data, m_data + m_size, other.m_data);
    }

    /**
     * @brief Copy assignment operator.
     * 
     * @param other DynamicArray rhs of the operator.
     * @return DynamicArray& 
     */
    DynamicArray& operator=(const DynamicArray &other)
    {
        if (this != &other)
        {
            if (m_size != other.m_size)
            {
                delete[] m_data;

                m_size = other.m_size;
                m_capacity = other.m_capacity;

                if (other.m_size > 0)
                {
                    m_data = new value_type[other.m_size];
                }
                else
                {
                    m_data = nullptr;
                }    
            }

            std::copy(m_data, m_data + m_size, other.m_data);
        }
    }

    /**
     * @brief Move constructor.
     * 
     * @param other 
     */
    DynamicArray(DynamicArray &&other) noexcept :
        m_size(std::move(other.m_size)),
        m_capacity(std::move(other.m_capacity)),
        m_data(std::move(other.m_data))
    {
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }

    /**
     * @brief Move assignment operator.
     * 
     * @param other 
     * @return DynamicArray& 
     */
    DynamicArray& operator=(DynamicArray &&other) noexcept
    {
        if(this != &other)
        {
            delete[] m_data;

            m_size = std::move(other.m_size);
            m_capacity = std::move(other.m_capacity);
            m_data = std::move(other.m_data);

            other.m_size = 0;
            other.m_capacity = 0;
            other.m_data = nullptr;
        }

        return *this;
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
        return *begin();
    }

    constexpr const pointer data() const noexcept
    {
        return *begin();
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
        return reverse_iterator(m_data);
    }
    
    constexpr const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(m_data);
    }

    constexpr const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator(m_data);
    }

    constexpr reverse_iterator rend() noexcept
    {
        return reverse_iterator(m_data + m_size);
    }
    
    constexpr const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(m_data + m_size);
    }

    constexpr const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator(m_data + m_size);
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
        return std::numeric_limits<size_type>::max();
    }

    constexpr void reserve(const size_type new_capacity)
    {
        if (m_capacity != new_capacity)
        {
            m_capacity = new_capacity;

            pointer temp = nullptr;
            temp = new value_type[m_capacity];
            std::copy(temp, temp + m_size, m_data);

            delete[] m_data;
            m_data = temp;
        }
    }

    constexpr size_type capacity() const noexcept
    {
        return m_capacity;
    }

    constexpr void shrink_to_fit()
    {
        if (m_size != m_capacity)
        {
            if (m_size != m_capacity)
            {
                reserve(m_size);
            }
        }
    }
    
    /**************************************/
    /*             MODIFIERS              */
    /**************************************/
    constexpr void clear()
    {
        if (m_size > 0)
        {
            delete[] m_data;

            m_size = 0;
            m_capacity = 0;
            m_data = nullptr;
        }
    }

    /**
     * @brief Push backs the *value* at the end of the array.
     *
     * @param dynmaic_array The dynamic array.
     * @param value The value to append to the array.
     */
    constexpr void push_back(const_reference value)
    {
        if (m_size == m_capacity)
        {
            size_type new_capacity = m_capacity * 2;

            reserve(new_capacity);
        }

        m_data[m_size] = value;
        m_size++;
    }

    /**
     * @brief Pop backs the value at the end of the vector.
     */
    constexpr void pop_back()
    {
        if (m_size > 0)
        {
            m_size--;
        }
    }

    constexpr void resize(size_type count)
    {
        resize(count, 0);
    }

    constexpr void resize(size_type count, const value_type& value)
    {
        if (m_size >= count)
        {
            m_size = count;
        }
        else if(m_capacity < count) // m_size < count
        {
            reserve(count);
            std::fill(m_data + m_size, m_data + m_capacity, value_type());
            m_size = count;
        }
        else // capacity is large enough
        {
            std::fill(m_data + m_size, m_data + m_capacity, value_type());
            m_size = count;
        }
    }

private:
    size_type m_size;
    size_type m_capacity;
    pointer m_data;
};