#include <cstdint>
#include <iostream>

constexpr static std::uint32_t MAX_NUM_CALLS = 4U;

void worker()
{
    static std::uint32_t counter = 0;

    if (counter == 0)
        std::cout << "First called!" << std::endl;
    else if (counter < MAX_NUM_CALLS)
        std::cout << "Called again!" << std::endl;
    else
        std::cout << "Out of ressources!" << std::endl;

    ++counter;
}

int main()
{
    for (std::uint32_t i = 0; i < 7U; ++i)
        worker();

    return 0;
}
