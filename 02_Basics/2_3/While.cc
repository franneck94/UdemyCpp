#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t sum = 0;

    while (sum < 10)
    {
        std::cout << "\nCurrent Sum: " << sum << " Enter the next value: ";
        std::int32_t input = 0;
        std::cin >> input;

        sum += input;
    }

    return 0;
}
