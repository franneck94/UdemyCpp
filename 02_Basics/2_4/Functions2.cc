#include <cstdint>
#include <iostream>

std::int32_t user_input()
{
    std::int32_t number = 0;
    std::cout << "Please enter a number: ";
    std::cin >> number;

    return number;
}

bool is_even(std::int32_t number)
{
    return number % 2 == 0;
}

int main()
{
    std::int32_t user_number = user_input();
    std::cout << user_number << '\n';

    bool result = is_even(user_number);
    std::cout << "Is Even? " << std::boolalpha << result << '\n';

    return 0;
}
