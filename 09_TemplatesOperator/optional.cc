#include <iostream>
#include <optional>

std::optional<std::string> func1(bool b)
{
    if (b)
        return "Hello World";
    return std::nullopt;
}

std::optional<std::string> func2(bool b)
{
    return b ? std::optional<std::string>{"Hello World"} : std::nullopt;
}

void func3(std::optional<std::string> s)
{
    if (s.has_value())
        std::cout << s.value() << std::endl;
}

int main()
{
    const auto r1 = func1(true);
    const auto r2 = func2(true);

    func3(r1);
    func3(r2);

    return 0;
}
