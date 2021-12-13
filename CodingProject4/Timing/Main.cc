#include <iostream>

#include "Matrix.h"
#include "Timer.h"

int main()
{
    cppmath::Matrix<double> m1(250, 250, -1.3);
    cppmath::Matrix<double> m2(250, 250, -1.3);

    int num_runs = 10;
    double total_time = 0.0;

    for (int i = 0; i < num_runs; ++i)
    {
        cpptiming::Timer t;
        cppmath::Matrix<double> m3 = m1 * m2;
        total_time += t.elapsed_time<cpptiming::millisecs, double>();
    }

    std::cout << "Mean time: " << total_time / num_runs << " ms" << std::endl;

    return 0;
}
