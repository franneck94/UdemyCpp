#include <iostream>

#include "Image.h"

int main()
{
    Image my_image1(100, 400);
    my_image1.save_image("image.bmp");

    return 0;
}
