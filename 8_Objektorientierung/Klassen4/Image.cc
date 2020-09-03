#include <iostream>

#include <malloc.h>
#include <memory.h>
#include <stdio.h>

#pragma warning(disable : 4996)
#include "Image.h"

// Konstruktor
Image::Image(const unsigned int &width, const unsigned int &height, const uchar &value)
    : m_value(value), m_width(width), m_height(height), m_matrix(m_width, std::vector<uchar>(m_height, value))
{
    std::cout << "Image created with width: " << m_width << " height: " << m_height << std::endl;
}

// Destruktor
Image::~Image()
{
    std::cout << "Image destroyed" << std::endl;
}

void Image::save_image(const char *file_name) const
{
    FILE *f;
    uchar *img = NULL;
    img = (uchar *)malloc(3 * m_width * m_height);
    memset(img, 0, sizeof(img));
    int filesize = 54 + 3 * m_width * m_height;

    for (int x = 0; x < m_width; x++)
    {
        for (int y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = (uchar)(m_matrix[x][y] % 256);
            img[(x + y * m_width) * 3 + 1] = (uchar)(m_matrix[x][y] % 256);
            img[(x + y * m_width) * 3 + 0] = (uchar)(m_matrix[x][y] % 256);
        }
    }

    uchar bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    uchar bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    uchar bmppad[3] = {0, 0, 0};

    bmpfileheader[2] = (uchar)(filesize);
    bmpfileheader[3] = (uchar)(filesize >> 8);
    bmpfileheader[4] = (uchar)(filesize >> 16);
    bmpfileheader[5] = (uchar)(filesize >> 24);

    bmpinfoheader[4] = (uchar)(m_width);
    bmpinfoheader[5] = (uchar)(m_width >> 8);
    bmpinfoheader[6] = (uchar)(m_width >> 16);
    bmpinfoheader[7] = (uchar)(m_width >> 24);
    bmpinfoheader[8] = (uchar)(m_height);
    bmpinfoheader[9] = (uchar)(m_height >> 8);
    bmpinfoheader[10] = (uchar)(m_height >> 16);
    bmpinfoheader[11] = (uchar)(m_height >> 24);

    f = fopen(file_name, "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (int i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad, 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
}

// Getter
unsigned int Image::get_width() const
{
    return m_width;
}

unsigned int Image::get_height() const
{
    return m_height;
}

// Setter
void Image::set_width(unsigned int new_width)
{
    m_width = new_width;
}

void Image::set_height(unsigned int new_height)
{
    m_height = new_height;
}