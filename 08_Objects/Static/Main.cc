#include <iostream>
#include <string>

#include "Circle.h"


int main()
{
    auto c1 = Circle{2.0F};

    std::cout << c1.compute_area() << std::endl;
    std::cout << c1.get_pi() << std::endl;
    std::cout << Circle::get_pi() << std::endl;

    return 0;
}
