#include <array>
#include <format>
#include <iostream>

int main()
{
    const auto name = "John";
    const auto lastname = "Lennon";
    const auto age = 42;

    const auto my_str1 =
        std::string{name} + std::string{lastname} + std::to_string(age);
    std::cout << my_str1 << '\n';

    const auto my_str2 = std::format("{1} {0} is {2}", name, lastname, age);
    std::cout << my_str2 << '\n';

    std::cout << std::format("{0} hex is {0:08X}", 42) << '\n';
    std::cout << std::format("{0} bin is {0:08B}", 42) << '\n';

    return 0;
}
