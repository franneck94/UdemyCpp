#include <iostream>
#include <compare>

struct MyDouble
{
    double value;
    explicit constexpr MyDouble(double val): value{val} { }
    auto operator<=>(const MyDouble&) const = default;
};

int main()
{
    MyDouble d1(2011);
    MyDouble d2(2014);

    std::cout << (bool)(d1 < d2) << std::endl;
}