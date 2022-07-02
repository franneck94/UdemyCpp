#include <iostream>
#include <optional>

std::optional<std::string> func1(const bool b)
{
    if (b)
        return "Hello World";
    return {};
}

std::optional<std::string> func2(const bool b)
{
    return b ? std::optional<std::string>{"Hello World"} : std::nullopt;
}

void func3(std::optional<std::string> s = std::nullopt)
{
    if (s.has_value())
        std::cout << s.value() << '\n';
    else
        std::cout << "None value...\n";
}

int main()
{
    const auto r1 = func1(false);
    const auto r2 = func2(false);

    func3(r1);
    func3(r2);
    func3();

    return 0;
}
