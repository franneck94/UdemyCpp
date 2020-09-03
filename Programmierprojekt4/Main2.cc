//#include <iostream>
//#include <string>
//#include <vector>
//#include <iterator>
//#include <algorithm>
//#include <random>
//#include <chrono>
//#include <functional>
//#include <chrono>
//#include <cassert>
//
//#include "Timer.h"
//
//using std::cout;
//using std::endl;
//using std::cin;
//using std::string;
//using std::vector;
//
//int main()
//{
//	double time = 0.0;
//
//	Timer t;
//
//	unsigned long sum = 0;
//	for (int i = 0; i < 1'000'000; i++)
//	{
//		sum += 1;
//	}
//	//std::cout << sum << std::endl;
//
//	time = t.elapsed_time<microsecs, double>();
//	std::cout << "Time: " << time << std::endl;
//
//	return 0;
//}