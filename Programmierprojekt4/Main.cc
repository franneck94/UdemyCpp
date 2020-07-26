//#include <iostream>
//
//#include "Matrix.h"
//#include "Timer.h"
//
//int main()
//{
//	Matrix<double> m1(200, 200, 1.0);
//	Matrix<double> m2(200, 200, 2.0);
//
//	int num_runs = 10;
//	double total_time = 0.0;
//
//	for (int i = 0; i < num_runs; ++i)
//	{
//		Timer t;
//		Matrix<double> m3 = m1 * m2;
//		total_time += t.elapsed_time<millisecs, double>();
//	}
//
//	std::cout << "Time: " << total_time / num_runs << "ms" << std::endl;
//	// Time: 18.6ms
//
//	return 0;
//}