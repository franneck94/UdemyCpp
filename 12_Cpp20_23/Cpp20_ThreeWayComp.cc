#include <compare>
#include <iostream>

class ValueType
{
public:
    explicit constexpr ValueType(const double val) : value{val} {};

    auto operator<=>(const ValueType &) const = default;

    double value;
};

int main()
{
    const auto d1 = ValueType(2011);
    const auto d2 = ValueType(2014);

    std::cout << std::boolalpha;
    std::cout << "d1 < d2:  " << std::boolalpha << (d1 < d2) << '\n';
    std::cout << "d1 > d2:  " << std::boolalpha << (d1 > d2) << '\n';
    std::cout << "d1 == d2: " << std::boolalpha << (d1 == d2) << '\n';
    std::cout << "d1 != d2: " << std::boolalpha << (d1 != d2) << '\n';
}
