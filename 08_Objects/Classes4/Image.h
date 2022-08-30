#include <cstdint>
#include <vector>

using GrayscaleMatrix = std::vector<std::vector<std::uint8_t>>;

class Image
{
public:
    Image(const std::uint32_t width, const std::uint32_t height);
    ~Image();

    void save_image(const char *file_name) const;

    std::uint32_t get_width() const;
    std::uint32_t get_height() const;
    GrayscaleMatrix get_matrix() const;

    void set_pixel(const std::uint32_t x,
                   const std::uint32_t y,
                   const std::uint8_t value);

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
    GrayscaleMatrix m_matrix;
};
