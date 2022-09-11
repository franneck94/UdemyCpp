#include <cstdint>
#include <iostream>

constexpr static std::uint32_t NUM_PLAYERS2 = 2U;

void f()
{
    static std::uint32_t counter = 0;

    std::cout << "Called f: " << counter << std::endl;

    ++counter;
}

int main()
{
    f();
    f();
    f();
    f();

    return 0;
}
