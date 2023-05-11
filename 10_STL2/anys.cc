#include <any>
#include <iostream>
#include <string>

template <typename T>
bool is_type(const std::any &a)
{
    return a.type() == typeid(T);
}

// void*

int main()
{
    auto a = std::any{42}; // integer 42
    a = 42.0;              // double 42.0
    a = std::string{"42"}; // std::string "42"

    std::cout << "int: " << std::boolalpha << is_type<int>(a) << '\n';
    std::cout << "dbl: " << std::boolalpha << is_type<double>(a) << '\n';
    std::cout << "str: " << std::boolalpha << is_type<std::string>(a) << '\n';

    std::cout << "has_value: " << std::boolalpha << a.has_value() << '\n';

    auto d = std::any_cast<std::string>(a);
    std::cout << d << '\n';

    return 0;
}
