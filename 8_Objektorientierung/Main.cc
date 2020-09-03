#include <iostream>

#include "Image.h"

int main()
{
    Image img;

    std::cout << img.get_width() << std::endl;
    std::cout << img.get_height() << std::endl;

    return 0;
}