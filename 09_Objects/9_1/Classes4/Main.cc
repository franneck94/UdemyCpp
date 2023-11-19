#include <iostream>

#include "Image.h"

int main()
{
    Image my_image1(100, 400);

    std::cout << my_image1.get_height() << '\n';
    std::cout << my_image1.get_width() << '\n';
    std::cout << static_cast<int>(my_image1.get_matrix()[0][0]) << '\n';
    my_image1.set_pixel(10, 10, 255); // [0, 255]
    my_image1.set_pixel(11, 11, 255); // [0, 255]
    my_image1.set_pixel(10, 11, 255); // [0, 255]
    my_image1.set_pixel(11, 10, 255); // [0, 255]

    my_image1.save_image("image.bmp");

    return 0;
}
