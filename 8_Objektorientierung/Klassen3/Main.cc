#include <iostream>

#include "Image.h"

int main()
{
    {
        Image img(100, 400, 0);
        img.save_image("image.bmp");
    }

    return 0;
}