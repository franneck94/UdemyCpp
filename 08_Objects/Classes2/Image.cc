#include <iostream>

#include "Image.h"

Image::Image(const std::uint32_t width, const std::uint32_t height)
    : m_width(width), m_height(height),
      m_matrix(m_width, std::vector<std::uint8_t>(m_height, 0))
{
    std::cout << "Image object created with shape=(" << width << "," << height
              << ")!\n";
}

Image::~Image()
{
    std::cout << "Image object destroyed!\n";
}
