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

	// Save Image
	void save_image(const char *file_name) const;

	// Getter
	unsigned int get_width() const;
	unsigned int get_height() const;
	// Setter
	void set_width(unsigned int new_width);
	void set_height(unsigned int new_height);

private:
	uchar m_value;
	unsigned int m_width;
	unsigned int m_height;
	Matrix_uchar m_matrix;
};