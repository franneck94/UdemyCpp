#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t sum = 0U;

    while (sum < 10U)
    {
        std::cout << "\nCurrent Sum: " << sum << " Enter the next value: ";
        std::int32_t input = 0U;
        std::cin >> input;

        sum += input;
    }

    return 0;
}
