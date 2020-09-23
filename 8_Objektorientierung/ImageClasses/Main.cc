#include <iostream>

#include "Image.h"

void image_code()
{
	BasePixelValue b;

	GrayscaleImage image1(100, 400);
	image1.fill_image({122});
	image1.set_pixel(0, 100, {190});
	image1.set_pixel(1, 100, {190});
	image1.set_pixel(0, 99, {190});
	image1.set_pixel(1, 99, {190});
	image1.save_image("grayscale_image.bmp");

	RGBImage image2(100, 400);
	image2.fill_image({0, 0, 255});
	image2.set_pixel(0, 100, {0, 255, 0});
	image2.set_pixel(1, 100, {0, 255, 0});
	image2.set_pixel(0, 99, {0, 255, 0});
	image2.set_pixel(1, 99, {0, 255, 0});
	image2.save_image("rgb_image.bmp");
}

int main()
{
	image_code();

	return 0;
}