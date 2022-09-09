#include <cstdint>
#include <iostream>

void worker()
{
    static constexpr std::uint32_t max_num_tasks = 4U;
    static std::uint32_t counter = 0U;

    if (counter < max_num_tasks)
        std::cout << "Doing my work!\n";
    else
        std::cout << "Out of energy!\n";

    ++counter;
}

int main()
{
    for (std::uint32_t i = 0U; i < 7U; ++i)
        worker();

    return 0;
}
