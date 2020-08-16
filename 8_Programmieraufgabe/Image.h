#pragma once

#include <vector>
#include <string>

typedef unsigned char uchar;
typedef std::vector<std::vector<uchar>> Matrix_uchar;

class GrayImage
{
public:
	GrayImage(
		int input_width, 
		int input_height, 
		int input_value);

	void save_image(
		const char *file_name) const;
	int get_width() const;
	int get_height() const;
	void set_pixel(
		const int &x, 
		const int &y, 
		const uchar &value);

	// Aufgabe 1
	void clear_image();
	// Aufgabe 2 
	void resize_image(
		const int &new_width, 
		const int &new_height);
	// Aufgabe 3
	void fill_image(
		const uchar &value);
	// Aufgabe 4
	void draw_line(
		const int &x1,
		const int &y1,
		const int &x2,
		const int &y2,
		const uchar &value);

private:
	int m_width;
	int m_height;
	Matrix_uchar m_matrix;
};