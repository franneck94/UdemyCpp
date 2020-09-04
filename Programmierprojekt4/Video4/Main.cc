#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <functional>

#include "Timer.h"

int main()
{
    double time = 0.0;

    cpptiming::Timer t;

    unsigned long sum = 0;
    for (int i = 0; i < 1'000'000; i++)
    {
        sum += 1;
    }
    //std::cout << sum << std::endl;

    time = t.elapsed_time<cpptiming::microsecs, double>();
    std::cout << "Time: " << time << std::endl;

    return 0;
}