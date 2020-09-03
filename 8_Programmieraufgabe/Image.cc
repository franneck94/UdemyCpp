#include <iostream>
#include <vector>
#include <cmath>

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#pragma warning(disable : 4996)
#include "Image.h"

GrayImage::GrayImage(
	int input_width,
	int input_height,
	int input_value) : m_width(input_width),
					   m_height(input_height),
					   m_matrix(m_width, std::vector<uchar>(m_height, input_value))
{
	std::cout << "Width of GrayImage: " << m_width << std::endl;
	std::cout << "Height of GrayImage: " << m_height << std::endl;
}

int GrayImage::get_width() const
{
	return m_width;
}

int GrayImage::get_height() const
{
	return m_height;
}

void GrayImage::save_image(
	const char *file_name) const
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

void GrayImage::set_pixel(
	const int &x,
	const int &y,
	const uchar &value)
{
	m_matrix[y][x] = value;
}

// Aufgabe 1
void GrayImage::clear_image()
{
	m_matrix.clear();
	m_height = 0;
	m_width = 0;
}

// Aufgabe 2
void GrayImage::resize_image(
	const int &new_width,
	const int &new_height)
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

// Aufgabe 3
void GrayImage::fill_image(
	const uchar &value)
{
	for (auto &col : m_matrix)
	{
		std::fill(col.begin(), col.end(), value);
	}
}

// Aufgabe 4
void GrayImage::draw_line(
	const int &x1,
	const int &y1,
	const int &x2,
	const int &y2,
	const uchar &value)
{
	int length = 0;

	if (x1 < m_width && x1 >= 0 &&
			x2 < m_width && x2 >= 0 &&
			y1 < m_height && y1 >= 0 &&
			y2 < m_height && y2 >= 0 &&
			(x1 == x2) ||
		(y1 == y2))
	{
		std::cout << "Draw line!" << std::endl;
		std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << std::endl;

		// Draw horizontal line
		if (x1 == x2)
		{
			std::cout << "Same x!" << std::endl;

			if (y1 < y2)
			{
				length = y2 - y1;
				std::cout << "With length: " << length + 1 << std::endl;
				;

				for (int i = 0; i != length; ++i)
				{
					set_pixel(x1, y1 + i, value);
				}
			}
			else
			{
				length = y1 - y2;
				std::cout << "With length: " << length + 1 << std::endl;
				;

				for (int i = 0; i != length; ++i)
				{
					set_pixel(x1, y2 + i, value);
				}
			}
		}
		// Draw vertical line
		else if (y1 == y2)
		{
			std::cout << "Same y!" << std::endl;

			if (x1 < x2)
			{
				length = x2 - x1;
				std::cout << "With length: " << length + 1 << std::endl;
				;

				for (int i = 0; i != length; ++i)
				{
					set_pixel(x1 + i, y1, value);
				}
			}
			else
			{
				length = x1 - x2;
				std::cout << "With length: " << length + 1 << std::endl;
				;

				for (int i = 0; i != length; ++i)
				{
					set_pixel(x2 + i, y1, value);
				}
			}
		}
	}
	else
	{
		std::cout << "Line Error" << std::endl;
		std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << std::endl;
	}
}