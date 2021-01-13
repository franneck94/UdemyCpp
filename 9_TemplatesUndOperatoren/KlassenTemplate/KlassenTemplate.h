#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

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
	double m_mean;
	int m_num_samples;
	std::vector<T> m_samples;
};
