#include <iostream>

#include "Image.h"

int main()
{
    {
        Image img(100, 400, 0);
        img.save_image("image.bmp");

        std::cout << img.get_width() << " " << img.get_height() << std::endl;
        img.set_width(200);
        img.set_height(300);
        std::cout << img.get_width() << " " << img.get_height() << std::endl;
    }

    return 0;
}