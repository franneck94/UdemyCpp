#include <cstdint>

class Image
{
public:
    // Konstruktor
    Image(const std::uint32_t width, const std::uint32_t height);

    // Destructor
    ~Image();

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
};
