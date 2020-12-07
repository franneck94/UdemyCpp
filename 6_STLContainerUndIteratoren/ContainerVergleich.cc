#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <random>
#include <typeinfo>
#include <chrono>

#define RUNS 50'000
#define container std::list<int>

/*
1. Insert
2. Delete
3. Sum
4. Change Value by Index
5. Find Value by Index

std::vector (50k):
	Elapsed time: 101.389
	Elapsed time: 70.442
	Elapsed time: 16.908
	Elapsed time: 0.077
	Elapsed time: 2.714

std::list (50k):
	Elapsed time: 3.157
	Elapsed time: 4.048
	Elapsed time: 29.598
	Elapsed time: 3.845
	Elapsed time: 3491.19

std::vector (100k):
	Elapsed time: 449.012
	Elapsed time: 332.788
	Elapsed time: 12.903
	Elapsed time: 0.135
	Elapsed time: 4.739

std::list (100k):
	Elapsed time: 6.695
	Elapsed time: 7.237
	Elapsed time: 32.366
	Elapsed time: 9.288
	Elapsed time: 14900.1

std::vector (200k):
	Elapsed time: 2009.89
	Elapsed time: 1659.61
	Elapsed time: 17.066 (2,23x)
	Elapsed time: 0.262 (84x)
	Elapsed time: 9.759 (6265x)

std::list (200k):
	Elapsed time: 13.192 (153x)
	Elapsed time: 16.324 (102x)
	Elapsed time: 37.934
	Elapsed time: 21.982
	Elapsed time: 62651.1
*/

void insertion()
{
	container c(100, 0);
	std::iota(c.begin(), c.end(), 0);

	auto it = c.begin();

	for (int i = 0; i < RUNS; ++i)
	{
		it = c.insert(it, 0);
	}
}

void deletion()
{
	container c(RUNS, 0);
	std::iota(c.begin(), c.end(), 0);

	for (int i = 0; i < RUNS - 1; ++i)
	{
		c.erase(c.begin());
	}
}

void summing()
{
	std::random_device gen;
	std::uniform_int_distribution<int> dist(-100, 100);

	container c(RUNS);
	std::generate(c.begin(), c.end(), [&]() { return dist(gen); });

	unsigned long sum = 0;

	for (auto it = c.begin(); it != c.end(); ++it)
	{
		sum += *it;
	}
}

void indexing1_vec()
{
	std::vector<int> c(RUNS, 0);
	std::iota(c.begin(), c.end(), 0);

	unsigned long sum = 0;

	for (int i = 0; i < c.size() - 1; ++i)
	{
		c[i] = c[i + 1];
	}
}

void indexing1_list()
{
	std::list<int> c(RUNS, 0);
	std::iota(c.begin(), c.end(), 0);

	unsigned long sum = 0;

	for (auto it = c.begin(); it != c.end()--; ++it)
	{
		*it = *it++;
	}
}

void indexing2_vec()
{
	std::vector<int> c(RUNS, 0);
	std::iota(c.begin(), c.end(), 0);

	int index = 0;
	std::random_device gen;
	std::uniform_int_distribution<int> dist(0, RUNS);

	for (int i = 0; i < RUNS; ++i)
	{
		index = dist(gen);
		c[index] = 42;
	}
}

void indexing2_list()
{
	std::list<int> c(RUNS, 0);
	std::iota(c.begin(), c.end(), 0);

	int index = 0;
	std::random_device gen;
	std::uniform_int_distribution<int> dist(0, RUNS);

	for (int i = 0; i < RUNS; ++i)
	{
		index = dist(gen);
		auto it = c.begin();

		for (int j = 0; j < index; ++j)
		{
			it++;
		}

		*it = 42;
	}
}

int main()
{
	std::cout << "START" << std::endl;

	{
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
		start = std::chrono::high_resolution_clock::now();
		insertion();
		std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
		int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Elapsed time: " << elapsed_milliseconds / 1000.0 << std::endl;
	}

	{
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
		start = std::chrono::high_resolution_clock::now();
		deletion();
		std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
		int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Elapsed time: " << elapsed_milliseconds / 1000.0 << std::endl;
	}

	{
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
		start = std::chrono::high_resolution_clock::now();
		summing();
		std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
		int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Elapsed time: " << elapsed_milliseconds / 1000.0 << std::endl;
	}

	{
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
		start = std::chrono::high_resolution_clock::now();
		if (typeid(container) == typeid(std::vector<int>))
			indexing1_vec();
		else if (typeid(container) == typeid(std::list<int>))
			indexing1_list();
		std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
		int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Elapsed time: " << elapsed_milliseconds / 1000.0 << std::endl;
	}

	{
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
		start = std::chrono::high_resolution_clock::now();
		if (typeid(container) == typeid(std::vector<int>))
			indexing2_vec();
		else if (typeid(container) == typeid(std::list<int>))
			indexing2_list();
		std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
		int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << "Elapsed time: " << elapsed_milliseconds / 1000.0 << std::endl;
	}

	std::cout << "DONE" << std::endl;

	return 0;
}