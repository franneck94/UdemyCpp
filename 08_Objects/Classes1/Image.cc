#include <iostream>

#include "Image.h"

Image::Image()
{
    m_width = 0;
    m_height = 0;

    std::cout << "Created empty image object!" << std::endl;
}

Image::Image(const unsigned int &width, const unsigned int &height)
{
    m_width = width;
    m_height = height;

    std::cout << "Created image object with shape=(" << m_width << "," << m_height << ")!"
              << std::endl;
}

Image::~Image()
{
    std::cout << "Image object destroyed!" << std::endl;
}
