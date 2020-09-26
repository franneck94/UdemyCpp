#include <iostream>
#include <chrono>

#include "Matrix.h"

int main()
{
	cppmath::Matrix<double> m1(250, 250, -1.3);
	cppmath::Matrix<double> m2(250, 250, -1.3);

  auto start = std::chrono::high_resolution_clock::now();
  cppmath::Matrix<double> m3 = m1 * m2;
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> ms = end - start;
  std::cout << std::endl << "Time in ms: " << ms.count();

  // 1: Time in ms: 14.6428
  // 2: Time in ms: 8.4694
  // 4: Time in ms: 7.0167
  // 6: Time in ms: 5.6923
  // 8: Time in ms: 4.1401
  // 10: Time in ms: 3.9459
  // 12: Time in ms: 4.6522

	return 0;
}