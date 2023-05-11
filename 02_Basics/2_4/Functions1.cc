#include <cstdint>
#include <iostream>

std::int32_t user_input()
{
    std::int32_t number = 0;
    std::cout << "Please enter a number: ";
    std::cin >> number;

    return number;
}

int main()
{
    std::int32_t n1 = user_input();
    std::cout << n1 << '\n';
    std::int32_t n2 = user_input();
    std::cout << n2 << '\n';
    std::int32_t n3 = user_input();
    std::cout << n3 << '\n';

    return 0;
}
