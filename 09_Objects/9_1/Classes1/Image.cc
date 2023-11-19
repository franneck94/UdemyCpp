#include <iostream>

#include "Image.h"

Image::Image(const std::uint32_t width, const std::uint32_t height)
{
    m_width = width;
    m_height = height;

    std::cout << "Image object created with shape=(" << width << "," << height
              << ")!\n";
}

Image::~Image()
{
    std::cout << "Image object destroyed!\n";
}
