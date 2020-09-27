#pragma once

#include <cstddef>
#include <utility>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <iterator>

/**************************************/
/*              ALLOCATOR             */
/**************************************/
template<typename T>
class StandardAllocator
{
public:
    using value_type        = T;
    using size_type         = std::size_t;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using pointer           = value_type*;
    using const_pointer     = const value_type*;

public:
    constexpr StandardAllocator() noexcept { }

    ~StandardAllocator() noexcept { }

    constexpr pointer allocate(size_type n) const
    {
        return static_cast<pointer>(::operator new(n * sizeof(value_type)));
    }

    constexpr void deallocate(pointer p) const noexcept
    {
        ::operator delete[](p);
    }
};

/**************************************/
/*          VECTOR ITERATOR           */
/**************************************/
template <class T>
class RandomAcessIterator
{
public:
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using reference         = T&;
    using pointer           = T*;
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

    constexpr bool operator==(const RandomAcessIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    constexpr bool operator!=(const RandomAcessIterator &other) const
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
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using reference         = T&;
    using pointer           = T*;
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

    constexpr bool operator==(const ReverseRandomAcessIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    constexpr bool operator!=(const ReverseRandomAcessIterator &other) const
    {
        return m_ptr != other.m_ptr;
    }

protected:
    value_type* m_ptr;
};

/**************************************/
/*            VECTOR CLASS            */
/**************************************/
template <class T, class Allocator = StandardAllocator<T>>
class DynamicArray
{
public:
    using value_type        = T;
    using allocator_type    = Allocator;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using pointer           = typename Allocator::pointer;
    using const_pointer     = typename Allocator::const_pointer;
public:
    using iterator = RandomAcessIterator<value_type>;
    using const_iterator = RandomAcessIterator<const value_type>;
    using reverse_iterator = ReverseRandomAcessIterator<value_type>;
    using const_reverse_iterator = ReverseRandomAcessIterator<const value_type>;

    /**************************************/
    /*        SPECIAL MEMBER FUNCTIONS    */
    /**************************************/
public:
    constexpr DynamicArray() : 
        m_size(0), m_capacity(0), m_data(nullptr)
    { 
    }

    constexpr DynamicArray(const size_type count, const_reference value, const Allocator& alloc = Allocator()):
        m_size(count), m_capacity(count), m_data(alloc.allocate(m_size))
    {
        std::fill(m_data, m_data + m_size, value);
    }

    constexpr explicit DynamicArray(size_type count, const Allocator& alloc = Allocator()) : 
        m_size(count), m_capacity(count), m_data(alloc.allocate(m_size))
    {
        std::fill(m_data, m_data + m_size, value_type());
    }

    template< class InputIt >
    constexpr DynamicArray(InputIt first, InputIt last, const Allocator& alloc = Allocator()) :
        m_size(std::distance(first, last)), m_capacity(m_size), m_data(alloc.allocate(m_size))
    {
        std::copy(first, last, m_data);
    }

    constexpr DynamicArray(std::initializer_list<T> init, const Allocator& alloc = Allocator()) :
        m_size(init.size()), m_capacity(m_size), m_data(alloc.allocate(m_size))
    {
        std::copy(init.begin(), init.end(), m_data);
    }

    ~DynamicArray() noexcept
    {
        if (m_data != nullptr)
        {
            Allocator alloc = Allocator();
            alloc.deallocate(m_data);
            m_data = nullptr;
        }
    }

    constexpr DynamicArray(const DynamicArray &other) :
        m_size(other.m_size),
        m_capacity(other.m_capacity),
        m_data(other.m_size > 0 ? new value_type[other.m_size] : nullptr)
    {
        std::copy(m_data, m_data + m_size, other.m_data);
    }

    constexpr DynamicArray& operator=(const DynamicArray &other)
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

    constexpr DynamicArray(DynamicArray &&other) noexcept :
        m_size(std::move(other.m_size)),
        m_capacity(std::move(other.m_capacity)),
        m_data(std::move(other.m_data))
    {
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }

    constexpr DynamicArray& operator=(DynamicArray &&other) noexcept
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
        m_size = 0;
    }

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

    constexpr void resize(size_type count, const value_type& value)
    {
        if (m_size >= count)
        {
            m_size = count;
        }
        else if(m_capacity < count) // m_size < count
        {
            reserve(count);
            std::fill(m_data + m_size, m_data + m_capacity, value);
            m_size = count;
        }
        else // capacity is large enough
        {
            std::fill(m_data + m_size, m_data + m_capacity, value);
            m_size = count;
        }
    }

private:
    size_type m_size;
    size_type m_capacity;
    pointer m_data;
};