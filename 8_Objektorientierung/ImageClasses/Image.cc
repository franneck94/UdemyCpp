#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>

#pragma warning(disable : 4996)
#include "Image.h"

/**********************/
/*        IMAGE       */
/**********************/
Image::Image(const unsigned int width, const unsigned int height) :
    m_width(width), m_height(height)
{

}

unsigned int Image::get_width() const
{
    return m_width;
}

unsigned int Image::get_height() const
{
    return m_height;
}

void Image::clear_image()
{
    m_matrix.clear();
    m_height = 0;
    m_width = 0;
}

void Image::resize_image(const unsigned int new_width, const unsigned int new_height)
{
    // New width
    if (new_width != m_width)
    {
        m_matrix.resize(new_width);
        m_width = new_width;
    }

    // New height
    if (new_height != m_height)
    {
        for (auto &col : m_matrix)
        {
            col.resize(new_height);
        }

        m_height = new_height;
    }
}

/**********************/
/*   GRAYSCALE IMAGE */
/**********************/
GrayscaleImage::GrayscaleImage(const unsigned int width, const unsigned int height) :
    Image(width, height),
    m_matrix(GrayscaleMatrix(m_width, std::vector<GrayscalePixelValue>(m_height, { 0 })))
{

}

void GrayscaleImage::set_pixel(const unsigned int x, const unsigned int y, const GrayscalePixelValue pixel_value)
{
    m_matrix[x][y] = pixel_value;
}

void GrayscaleImage::fill_image(const GrayscalePixelValue pixel_value)
{
    for (auto &col : m_matrix)
    {
        std::fill(col.begin(), col.end(), pixel_value);
    }
}

void GrayscaleImage::save_image(const char *file_name) const
{
    FILE *f;

    unsigned int num_bytes = 3 * m_width * m_height;
    uchar *img = (uchar *)(malloc(num_bytes));
    memset(img, 0, num_bytes);

    int filesize = 54 + 3 * m_width * m_height;

    for (unsigned int x = 0; x < m_width; ++x)
    {
        for (unsigned int y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = m_matrix[x][y].value % 256;
            img[(x + y * m_width) * 3 + 1] = m_matrix[x][y].value % 256;
            img[(x + y * m_width) * 3 + 0] = m_matrix[x][y].value % 256;
        }
    }

    uchar bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
    uchar bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0 };
    uchar bmppad[3] = { 0, 0, 0 };

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

    for (unsigned int i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad, 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
}

/**********************/
/*      RGB IMAGE     */
/**********************/
RGBImage::RGBImage(const unsigned int width, const unsigned int height) :
    Image(width, height),
    m_matrix(RGBMatrix(m_width, std::vector<RGBPixelValue>(m_height, RGBPixelValue{ 0, 0, 0 })))
{

}
void RGBImage::set_pixel(const unsigned int x, const unsigned int y, const RGBPixelValue pixel_value)
{
    m_matrix[x][y] = pixel_value;
}

void RGBImage::fill_image(const RGBPixelValue value)
{
    for (auto &col : m_matrix)
    {
        std::fill(col.begin(), col.end(), value);
    }
}

void RGBImage::save_image(const char *file_name) const
{
    FILE *f;

    unsigned int num_bytes = 3 * m_width * m_height;
    uchar *img = (uchar *)(malloc(num_bytes));
    memset(img, 0, num_bytes);

    int filesize = 54 + 3 * m_width * m_height;

    for (unsigned int x = 0; x < m_width; ++x)
    {
        for (unsigned int y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = m_matrix[x][y].value_red % 256;
            img[(x + y * m_width) * 3 + 1] = m_matrix[x][y].value_green % 256;
            img[(x + y * m_width) * 3 + 0] = m_matrix[x][y].value_blue % 256;
        }
    }

    uchar bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
    uchar bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0 };
    uchar bmppad[3] = { 0, 0, 0 };

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

    for (unsigned int i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad, 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
}
