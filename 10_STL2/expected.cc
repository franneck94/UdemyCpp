#include <expected>
#include <iostream>
#include <string>

using namespace std::string_literals;

enum class parse_error
{
    invalid_input
};

std::expected<std::string, parse_error> check(const bool flag)
{
    if (flag)
        return "true"s;
    return std::unexpected(parse_error::invalid_input);
}

int main()
{
    auto result1 = check(false);
    if (result1.has_value())
    {
        std::cout << "value: " << result1 << "\n";
    }
    else if (result1.error() == parse_error::invalid_input)
    {
        std::cout << "error!\n";
    }

    auto result2 = check(false);
    if (result2.has_value())
    {
        std::cout << "value: " << result1 << "\n";
    }
    else if (result2.error() == parse_error::invalid_input)
    {
        std::cout << "error!\n";
    }

    return 0;
}
