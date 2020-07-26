//#include <iostream>
//#include <string>
//#include <vector>
//#include <iterator>
//#include <algorithm>
//#include <functional>
//#include <random>
//#include <chrono>
//#include <thread>
//#include <numeric>
//
//#include "omp.h"
//
//using std::cout;
//using std::endl;
//using std::cin;
//using std::string;
//using std::vector;
//
//int main()
//{
//	// SETUP
//	std::random_device gen;
//	std::uniform_int_distribution<int> dist(-10, 10);
//	vector <int> vector_a(10'000'000, 0);
//	std::generate(vector_a.begin(), vector_a.end(), [&]() { return dist(gen); });
//
//	// SERIELL
//	auto start = std::chrono::high_resolution_clock::now();
//	long long sum_vector = serial_sum(vector_a);
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double, std::milli> ms = end - start;
//	cout << endl << "Serial time in ms: " << ms.count();
//	cout << endl << "Serial Sum: " << sum_vector << endl;
//
//	// PARALLEL
//	start = std::chrono::high_resolution_clock::now();
//	sum_vector = parallel_sum(vector_a);
//	end = std::chrono::high_resolution_clock::now();
//	ms = end - start;
//	cout << endl << "Parallel time in ms: " << ms.count();
//	cout << endl << "Parallel Sum: " << sum_vector << endl;
//
//	// REDUCE
//	start = std::chrono::high_resolution_clock::now();
//	sum_vector = std::reduce(vector_a.begin(), vector_a.end());
//	end = std::chrono::high_resolution_clock::now();
//	ms = end - start;
//	cout << endl << "Reduce time in ms: " << ms.count();
//	cout << endl << "Reduce Sum: " << sum_vector << endl;
//
//	// ACCUMULATE
//	start = std::chrono::high_resolution_clock::now();
//	sum_vector = std::accumulate(vector_a.begin(), vector_a.end(), 0, std::plus<int>());
//	end = std::chrono::high_resolution_clock::now();
//	ms = end - start;
//	cout << endl << "Accumulate time in ms: " << ms.count();
//	cout << endl << "Accumulate Sum: " << sum_vector << endl;
//
//	return 0;
//}