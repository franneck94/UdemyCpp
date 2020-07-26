#include <iostream>

#include "Image.h"

void image_code()
{
	//				  w,   h,  v 
	GrayImage image1(100, 400, 0);
	image1.save_image("image1.bmp");

	std::cout << "Create image with (100, 400)" << std::endl;
	std::cout << "Act height: " << image1.get_height() << std::endl;
	std::cout << "Act width: " << image1.get_width() << std::endl;

	image1.resize_image(500, 300);
	image1.fill_image(0);
	image1.save_image("image2.bmp");

	std::cout << "Resize to (500, 300)" << std::endl;
	std::cout << "New height: " << image1.get_height() << std::endl;
	std::cout << "New width: " << image1.get_width() << std::endl;

	//				 x1   y1  x2  y2  val
	image1.draw_line(0, 150, 200, 150, 123);
	image1.save_image("image3.bmp");

	//				 x1   y1  x2  y2  val
	image1.draw_line(150, 0, 150, 200, 123);
	image1.save_image("image4.bmp");
}

int main()
{
	image_code();

	return 0;
}