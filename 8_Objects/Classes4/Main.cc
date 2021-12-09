#include <iostream>

#include "Image.h"

int main()
{
    Image my_image1(100, 400);
    my_image1.save_image("image.bmp");

    std::cout << "Height: " << my_image1.get_height() << std::endl;
    my_image1.set_height(200);
    std::cout << "Height: " << my_image1.get_height() << std::endl;

    return 0;
}
