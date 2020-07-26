#pragma once

#include <chrono>
#include <iostream>

class Timer
{
public:
	Timer()
	{
		m_start_point = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		stop();
	}

	void stop()
	{
		auto end_point = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_point).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();
		auto duration = end - start;

		double ms = duration / 1000.0;

		std::cout << "Elapsed ms: " << ms << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start_point;
}