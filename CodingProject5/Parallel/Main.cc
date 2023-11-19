#include <iostream>

#include "Matrix.h"
#include "Timer.h"

/*
1:  67155.5 us
2:  39068.4 us
4:  25012.5 us
6:  19421.5 us
8:  15685.3 us
10: 13089.6 us
12: 12074.9 us
16: 13590.0 us
*/

namespace
{
constexpr auto NUM_RUNS = std::uint32_t{500};
}

int main()
{
    const auto m1 = Matrix<double>(500, 500, -1.0);
    const auto m2 = Matrix<double>(500, 500, -1.0);

    double total_time = 0.0;

    for (uint32_t i = 0; i < NUM_RUNS; ++i)
    {
        const auto t = Timer{};
        const auto m3 = m1 * m2;
        total_time += t.elapsed_time<microsecs, double>();
    }

    std::cout << "Mean time: " << total_time / NUM_RUNS << " us" << '\n';

    return 0;
}
