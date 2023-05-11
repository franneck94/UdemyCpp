#include <iostream>
#include <optional>
#include <string>

using namespace std::string_literals;

std::optional<std::string> check(const bool flag)
{
    if (flag)
        return "true"s;
    return {}; // std::nullopt
}

int main()
{
    auto v1 = std::optional<int>{42};
    std::cout << *v1 << '\n'; // 42

    auto v2 = std::optional<std::string>{"text"s};
    std::cout << v2.value() << '\n'; // text
    auto v3 = std::optional<std::string>{};
    std::cout << v3.value_or("default"s) << '\n'; // default

    std::cout << std::boolalpha << v3.has_value() << '\n';

    return 0;
}
