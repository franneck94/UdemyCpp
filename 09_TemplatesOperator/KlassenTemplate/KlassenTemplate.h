#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
class Statistic
{
public:
    Statistic<T>();
    ~Statistic<T>();

    T get_min() const;
    T get_max() const;
    double get_mean() const;
    void push_next_sample(T value);
    void print_data();

private:
    T m_min;
    T m_max;
    int m_num_samples;
    double m_mean;
    std::vector<T> m_samples;
};

template <typename T>
Statistic<T>::Statistic()
    : m_min(0), m_max(0), m_num_samples(0), m_mean(0.0), m_samples(0, 0)
{
}

template <typename T>
Statistic<T>::~Statistic()
{
}

template <typename T>
T Statistic<T>::get_min() const
{
    return m_min;
}

template <typename T>
T Statistic<T>::get_max() const
{
    return m_max;
}

template <typename T>
double Statistic<T>::get_mean() const
{
    return m_mean;
}

template <typename T>
void Statistic<T>::push_next_sample(T value)
{
    m_num_samples++;
    m_samples.push_back(value);

    if (m_num_samples == 1)
    {
        m_min = value;
        m_max = value;
        m_mean = value;
    }

    else
    {
        if (value < m_min)
            m_min = value;
        if (value > m_max)
            m_max = value;

        m_mean = (((m_num_samples - 1) * m_mean + value) / (m_num_samples));
    }
}

template <typename T>
void Statistic<T>::print_data()
{
    std::cout << "Max: " << m_max << std::endl;
    std::cout << "Min: " << m_min << std::endl;
    std::cout << "Mean: " << m_mean << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}
