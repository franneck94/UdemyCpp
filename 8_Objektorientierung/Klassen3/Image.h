#include <vector>

typedef unsigned char uchar;
typedef std::vector<std::vector<uchar>> Matrix_uchar;

class Image
{
public:
	// Konstruktor
	Image(const unsigned int &width, const unsigned int &height, const uchar &value);

	// Destruktor
	~Image();

	void save_image(const char *file_name) const;

private:
	uchar m_value;
	unsigned int m_width;
	unsigned int m_height;
	Matrix_uchar m_matrix;
};