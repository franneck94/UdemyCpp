#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>

#include "exercise.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

// Aufgabe 2
vector<bool> shuffle_till_equal(const BinaryArray &target, BinaryArray input)
{
	bool equal = false;
	int iteration = 1;

	while (!equal)
	{
		if(iteration % 100'000 == 0)
			cout << endl << "Iteration: " << iteration;
		++iteration;

		auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
		std::shuffle(input.begin(), input.end(), std::default_random_engine(timestamp));
	 
		if (std::equal(input.begin(), input.end(), target.begin()))
			equal = true;
	}

	return input;
}

// Aufgabe 3
vector<bool> smart_shuffle_till_equal(const BinaryArray &target, BinaryArray input)
{
	bool equal = false;
	vector<bool>::iterator first = input.begin();
	vector<bool>::iterator last = input.end();
	int iteration = 1;

	while (!equal)
	{
		if (iteration % 100000 == 0)
			cout << endl << "Iteration: " << iteration;
		++iteration;

		auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
		std::shuffle(first, last, std::default_random_engine(timestamp));

		int index = std::distance(input.begin(), first);

		if (*first == target[index])
			++first;

		if (first == last)
			equal = true;
	}

	return input;
}