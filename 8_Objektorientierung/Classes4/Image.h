#include <vector>

using uchar = unsigned char;
using GrayscaleMatrix = std::vector<std::vector<uchar>>;

class Image
{
public:
    // Konstruktor
    Image();
    Image(const unsigned int width, const unsigned int height);

    // Destruktor
    ~Image();

    // Getter
    unsigned int get_width() const;
    unsigned int get_height() const;

    // Setter
    void set_width(unsigned int new_width);
    void set_height(unsigned int new_height);

    void save_image(const char *file_name) const;

private:
    unsigned int m_width;
    unsigned int m_height;
    GrayscaleMatrix m_matrix;
};
