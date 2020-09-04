#include <iostream>

#include "Matrix.h"
#include "Vec.h"
#include "Timer.h"

int main()
{
	cppmath::Matrix<double> m1(200, 200, 1.0);
	cppmath::Matrix<double> m2(200, 200, 2.0);

	cppmath::Vec<double> v1(200, 42.0);
	cppmath::Vec<double> v2 = m1 * v1;

	//Matrix<int> m3(200, 200, 1);
	cppmath::Matrix<float> m4(200, 200, 1.0f);

	int num_runs = 10;
	double total_time = 0.0;

	for (int i = 0; i < num_runs; ++i)
	{
		cpptiming::Timer t;
		cppmath::Matrix<double> m3 = m1 * m2;
		total_time += t.elapsed_time<cpptiming::millisecs, double>();
	}

	std::cout << "Time: " << total_time / num_runs << "ms" << std::endl;
	// Time: 18.6ms

	return 0;
}