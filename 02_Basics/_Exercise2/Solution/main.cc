#include <cstdint>
#include <iostream>

void super_duper_example(const std::int32_t val)
{
    static constexpr std::int32_t reset_counter = 10;
    static std::int32_t counter = 0;

    if (val % 2 == 0)
    {
        counter++;
    }
    else if (val == reset_counter)
    {
        counter = 0;
    }
}

int main()
{


    return 0;
}
