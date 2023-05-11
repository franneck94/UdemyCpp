#include <array>
#include <cstdlib>
#include <cstring>
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

void Image::save_image(const char *file_name) const
{
    FILE *f = nullptr;

    auto num_bytes = 3 * m_width * m_height;
    auto *img = new std::uint8_t[num_bytes]{};

    auto filesize = 54 + 3 * m_width * m_height;

    for (std::uint32_t x = 0; x < m_width; ++x)
    {
        for (std::uint32_t y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 1] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 0] = m_matrix[x][y] % 256;
        }
    }

    auto bmpfileheader =
        std::array<std::uint8_t,
                   14>{'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    auto bmpinfoheader =
        std::array<std::uint8_t,
                   40>{40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    auto bmppad = std::array<std::uint8_t, 3>{0, 0, 0};

    bmpfileheader[2] = static_cast<std::uint8_t>(filesize);
    bmpfileheader[3] = static_cast<std::uint8_t>(filesize >> 8);
    bmpfileheader[4] = static_cast<std::uint8_t>(filesize >> 16);
    bmpfileheader[5] = static_cast<std::uint8_t>(filesize >> 24);

    bmpinfoheader[4] = static_cast<std::uint8_t>(m_width);
    bmpinfoheader[5] = static_cast<std::uint8_t>(m_width >> 8);
    bmpinfoheader[6] = static_cast<std::uint8_t>(m_width >> 16);
    bmpinfoheader[7] = static_cast<std::uint8_t>(m_width >> 24);
    bmpinfoheader[8] = static_cast<std::uint8_t>(m_height);
    bmpinfoheader[9] = static_cast<std::uint8_t>(m_height >> 8);
    bmpinfoheader[10] = static_cast<std::uint8_t>(m_height >> 16);
    bmpinfoheader[11] = static_cast<std::uint8_t>(m_height >> 24);

    f = fopen(file_name, "wb");
    if (f == nullptr)
    {
        delete[] img;
        img = nullptr;

        return;
    }

    fwrite(bmpfileheader.data(), 1, 14, f);
    fwrite(bmpinfoheader.data(), 1, 40, f);

    for (std::uint32_t i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad.data(), 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
    f = nullptr;

    delete[] img;
    img = nullptr;
}

std::uint32_t Image::get_width() const
{
    return m_width;
}

std::uint32_t Image::get_height() const
{
    return m_height;
}

GrayscaleMatrix Image::get_matrix() const
{
    return m_matrix;
}

void Image::set_pixel(const std::uint32_t x,
                      const std::uint32_t y,
                      const std::uint8_t value)
{
    m_matrix[x][y] = value;
}

// Exercise 1
void Image::clear_image()
{
    m_matrix.clear();
    m_height = 0;
    m_width = 0;
}

// Exercise 2
void Image::resize_image(const std::uint32_t new_width,
                         const std::uint32_t new_height)
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

// Exercise 3
void Image::fill_image(const std::uint8_t value)
{
    for (auto &col : m_matrix)
    {
        std::fill(col.begin(), col.end(), value);
    }
}

// Exercise 4
void Image::draw_line(const std::uint32_t x1,
                      const std::uint32_t y1,
                      const std::uint32_t x2,
                      const std::uint32_t y2,
                      const std::uint8_t value)
{
    int length = 0;

    if ((x1 < m_width) && (x2 < m_width) && (y1 < m_height) &&
        (y2 < m_height) && ((x1 == x2) || (y1 == y2)))
    {
        std::cout << "Draw line!" << '\n';
        std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << '\n';

        // Draw vertical line
        if (x1 == x2)
        {
            std::cout << "Same x!" << '\n';

            if (y1 < y2)
            {
                length = y2 - y1;
                std::cout << "With length: " << length + 1 << '\n';

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x1, y1 + i, value);
                }
            }
            else
            {
                length = y1 - y2;
                std::cout << "With length: " << length + 1 << '\n';

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x1, y2 + i, value);
                }
            }
        }
        // Draw horizontal line
        else if (y1 == y2)
        {
            std::cout << "Same y!" << '\n';

            if (x1 < x2)
            {
                length = x2 - x1;
                std::cout << "With length: " << length + 1 << '\n';

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x1 + i, y1, value);
                }
            }
            else
            {
                length = x1 - x2;
                std::cout << "With length: " << length + 1 << '\n';

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x2 + i, y1, value);
                }
            }
        }
    }
    else
    {
        std::cout << "Line Error" << '\n';
        std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << '\n';
    }
}
