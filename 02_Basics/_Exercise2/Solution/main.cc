#include <cstdint>
#include <iostream>

void super_duper_example(const std::int32_t val)
{
    constexpr std::int32_t reset_counter = 10;
    static std::int32_t counter = 0;

    if (val == reset_counter)
    {
        counter = 0;
        return;
    }

    if (val % 2 == 0)
    {
        counter++;
    }
}

int main()
{
    for (int i = 0; i < 11; i++)
    {
        super_duper_example(i);
    }

    return 0;
}
