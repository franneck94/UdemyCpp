#include <vector>

typedef unsigned char uchar;
typedef std::vector<std::vector<uchar>> Matrix_uchar;

class Image
{
public:
	// Konstruktor
	Image(const unsigned int &width, const unsigned int &height);

	// Destruktor
	~Image();

private:
	unsigned int m_width;
	unsigned int m_height;
	Matrix_uchar m_matrix;
};