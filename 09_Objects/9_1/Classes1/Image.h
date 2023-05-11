#include <cstdint>

class Image
{
public:
    // Constructor
    Image(const std::uint32_t width, const std::uint32_t height);

    // Destructor
    ~Image();

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
};
