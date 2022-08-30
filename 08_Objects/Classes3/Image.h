#include <cstdint>
#include <vector>

using GrayscaleMatrix = std::vector<std::vector<std::uint8_t>>;

class Image
{
public:
    Image(const std::uint32_t width, const std::uint32_t height);
    ~Image();

    void save_image(const char *file_name) const;

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
    GrayscaleMatrix m_matrix;
};
