#include <iostream>

#include "Image.h"

Image::Image(const std::uint32_t width, const std::uint32_t height)
{
    m_width = width;
    m_height = height;

    std::cout << "Created image object with shape=(" << m_width << "," << m_height
              << ")!" << std::endl;
}

Image::~Image()
{
    std::cout << "Image object destroyed!" << std::endl;
}
