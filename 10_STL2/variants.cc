#include <iostream>
#include <string>
#include <variant>
#include <vector>

using namespace std::string_literals;

// Union

int main()
{
    auto v = std::variant<int, double, std::string>{42};

    auto i1 = std::get<int>(v);
    std::cout << i1 << '\n';

    try
    {
        auto f = std::get<double>(v);
        std::cout << f << '\n';
    }
    catch (std::bad_variant_access const &e)
    {
        std::cout << e.what() << '\n'; // Unexpected index
    }

    auto vec = std::vector<std::variant<int, double>>{};

    v = 42.0;
    if (std::holds_alternative<double>(v))
    {
        std::cout << std::get<double>(v) << '\n';
    }

    if (!std::holds_alternative<int>(v))
    {
        std::cout << "No int!" << '\n';
    }

    return 0;
}
