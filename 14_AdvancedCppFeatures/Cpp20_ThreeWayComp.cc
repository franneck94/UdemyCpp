#include <compare>
#include <iostream>

struct Dummy
{
    double value;
    constexpr Dummy(double val) : value{val}
    {
    }
    auto operator<=>(const Dummy &) const = default;
};

int main()
{
    Dummy d1(2011);
    Dummy d2(2014);

    std::cout << std::boolalpha;
    std::cout << "d1 < d2:  " << (bool)(d1 < d2) << std::endl;
    std::cout << "d1 > d2:  " << (bool)(d1 > d2) << std::endl;
    std::cout << "d1 == d2: " << (bool)(d1 == d2) << std::endl;
    std::cout << "d1 != d2: " << (bool)(d1 != d2) << std::endl;
}
