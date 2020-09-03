#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>

#include "exercise.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();

	// Aufgabe 1
	std::random_device gen;
	std::bernoulli_distribution dist(0.5);

	BinaryArray target(20, 0);
	std::generate(target.begin(), target.end(), [&] { return dist(gen); });

	BinaryArray input(target.begin(), target.end());
	timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
	std::shuffle(input.begin(), input.end(), std::default_random_engine(timestamp));

	for (int i = 0; i < target.size(); ++i)
	{
		std::cout << "Target[" << i << "] = " << target[i] << std::endl;
	}

	for (int i = 0; i < input.size(); ++i)
	{
		std::cout << "Input[" << i << "] = " << input[i] << std::endl;
	}

	// Aufgabe 2
	cout << endl
		 << "Starting exercise 2";
	auto start = std::chrono::high_resolution_clock::now();
	BinaryArray result_exercise2 = shuffle_till_equal(target, input);
	auto end = std::chrono::high_resolution_clock::now();
	int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	cout << endl
		 << "Time for exercise 2 in ms: " << elapsed_milliseconds;
	cout << endl
		 << "Vectors are equal: " << std::equal(result_exercise2.begin(), result_exercise2.end(), target.begin());
	cout << endl;

	// Aufgabe 3
	cout << endl
		 << "Starting exercise 3";
	start = std::chrono::high_resolution_clock::now();
	BinaryArray result_exercise3 = smart_shuffle_till_equal(target, input);
	end = std::chrono::high_resolution_clock::now();
	elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	cout << endl
		 << "Time for exercise 3 in ms: " << elapsed_milliseconds;
	cout << endl
		 << "Vectors are equal: " << std::equal(result_exercise3.begin(), result_exercise3.end(), target.begin());
	cout << endl;

	return 0;
}