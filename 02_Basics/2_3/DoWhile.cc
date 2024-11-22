#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t sum = 10;

    do
    {
        std::cout << "\nCurrent Sum: " << sum << " Enter the next value: ";
        std::int32_t input = 0;
        std::cin >> input;

        sum += input;
    } while (sum < 10);

    return 0;
}
