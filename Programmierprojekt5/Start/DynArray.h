#pragma once

#include <cstddef>
#include <utility>
#include <limits>

template <typename T>
class DynamicArray
{
public:
    /**************************************/
    /*        SPECIAL MEMBER FUNCTIONS    */
    /**************************************/
    /**
     * @brief Create an empty dynamic array object
     */
    DynamicArray() : m_size(0), m_capacity(0), m_data(nullptr)
    { 

    }

    /**
     * @brief Create a dynamic array object
     */
    DynamicArray(const std::size_t length, T& value) :
        m_size(length), m_capacity(length), m_data(new T[length])
    {
        for (std::size_t i = 0; i < length; i++)
        {
            m_data[i] = value;
        }
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
        m_data(other.m_size > 0 ? new T[other.m_size] : nullptr)
    {
        for(std::size_t i = 0; i != m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
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
                    m_data = new T[other.m_size];
                }
                else
                {
                    m_data = nullptr;
                }    
            }

            for (std::size_t i = 0; i != m_size; ++i)
            {
                m_data[i] = other.m_data[i];
            }
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
    /*             MODIFIERS              */
    /**************************************/
    /**
     * @brief Push backs the *value* at the end of the array.
     *
     * @param dynmaic_array The dynamic array.
     * @param value The value to append to the array.
     */
    void push_back(T& value)
    {
        if (m_size == m_capacity)
        {
            std::size_t new_capacity = m_capacity * 2;

            reserve(new_capacity);
        }

        m_data[m_size] = value;
        m_size++;
    }

    /**
     * @brief Pop backs the value at the end of the vector.
     */
    void pop_back()
    {
        if (m_size > 0)
        {
            m_size--;
        }
    }

    /**************************************/
    /*            CAPACITY                */
    /**************************************/
    std::size_t size() const
    {
        return m_size;
    }

    constexpr std::size_t capacity() const noexcept
    {
        return m_capacity;
    }

    /**************************************/
    /*          ELEMENT ACCESS            */
    /**************************************/
    constexpr T& operator[](const std::size_t index) const
    {
        return m_data[index];
    }

    constexpr const T& operator[](const std::size_t index) const
    {
        return m_data[index];
    }

private:
    std::size_t m_size;
    std::size_t m_capacity;
    T* m_data;
};