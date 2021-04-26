#include <iostream>

#include "Matrix.h"
#include "Timer.h"

int main()
{
    cppmath::Matrix<double> m1(249, 249, -1.3);
    cppmath::Matrix<double> m2(249, 249, -1.3);

    int num_runs = 10;
    double total_time = 0.0;

    for (int i = 0; i < num_runs; ++i)
    {
        cpptiming::Timer t;
        cppmath::Matrix<double> m3 = m1 * m2;
        total_time += t.elapsed_time<cpptiming::millisecs, double>();
    }

    std::cout << "Mean time: " << total_time / num_runs << " ms" << std::endl;

    // 1: Time in ms: 14.4 ms
    // 2: Time in ms: 7.8 ms
    // 4: Time in ms: 4.2 ms
    // 6: Time in ms: 3.2 ms
    // 8: Time in ms: 2.9 ms
    // 10: Time in ms: 2.3 ms
    // 12: Time in ms: 2.8 ms

    return 0;
}
