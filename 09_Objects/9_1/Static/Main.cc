#include <iostream>
#include <string>

#include "Circle.h"


int main()
{
    auto c1 = Circle{2.0F};

    std::cout << c1.compute_area() << '\n';

    std::cout << c1.get_pi() << '\n';
    std::cout << Circle::get_pi() << '\n';

    return 0;
}
