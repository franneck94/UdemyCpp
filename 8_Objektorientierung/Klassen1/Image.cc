#include <iostream>

#include "Image.h"

// Konstruktor
Image::Image(const unsigned int &width, const unsigned int &height)
{
    m_width = width;
    m_height = height;

    std::cout << "Image created with width: " << m_width << " height: " << m_height << std::endl;
}

// Destruktor
Image::~Image()
{
    std::cout << "Image destroyed" << std::endl;
}