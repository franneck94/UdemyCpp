#include <iostream>

#include "Matrix.h"

int main()
{
  cppmath::Matrix<double> m1(2, 2, -1.3);
  cppmath::Matrix<double> m2(2, 3, -1.3);

  try
  {
    cppmath::Matrix<double> m3 = m1 + m2;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  try
  {
    cppmath::Matrix<double> m3 = m1 / 0;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}