#include <cstdint>
#include <iostream>

int main()
{
    const char last_name[] = "Schaffranek";
    std::cout << last_name << '\n';

    const std::int32_t values[]{1, 2, 3};
    std::cout << values << '\n';

    for (std::size_t i = 0; i < 4; i++)
    {
        std::cout << values[i] << '\n';
    }

    return 0;
}
