#include <iostream>

#include "Matrix.h"
#include "Timer.h"

/**
 * Serial: 3521.650 us
 *      2: 1880.130 us
 *      4: 1050.950 us
 *      6:  842.778 us
 *      8:  851.907 us
 *     10:  737.070 us
 *     12:  668.312 us
 */
int main()
{
    cppmath::Matrix<double> m1(250, 250, -1.0);
    cppmath::Matrix<double> m2(250, 250, -1.0);

    uint32_t num_runs = 1'000U;
    double total_time = 0.0;

    for (uint32_t i = 0; i < num_runs; ++i)
    {
        cpptiming::Timer t;
        cppmath::Matrix<double> m3 = m1 * m2;
        total_time += t.elapsed_time<cpptiming::microsecs, double>();
    }

    std::cout << "Mean time: " << total_time / num_runs << " us" << std::endl;

    return 0;
}
