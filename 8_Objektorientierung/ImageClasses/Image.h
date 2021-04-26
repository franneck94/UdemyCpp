#pragma once

#include <vector>

using uchar = uint8_t;

class BasePixelValue
{
public:
    BasePixelValue() { };
    virtual ~BasePixelValue() { };
};

class GrayscalePixelValue : public BasePixelValue
{
public:
    GrayscalePixelValue(uchar v) : value(v) { }
    ~GrayscalePixelValue() { }

    uchar value;
};

class RGBPixelValue : public BasePixelValue
{
public:
    RGBPixelValue(uchar v1, uchar v2, uchar v3) :
        value_red(v1), value_green(v2), value_blue(v3) { }
    ~RGBPixelValue() { }

    uchar value_red;
    uchar value_green;
    uchar value_blue;
};

using BaseMatrix = std::vector<std::vector<BasePixelValue>>;
using GrayscaleMatrix = std::vector<std::vector<GrayscalePixelValue>>;
using RGBMatrix = std::vector<std::vector<RGBPixelValue>>;

class Image
{
public:
    Image() = delete;
    Image(const unsigned int width, const unsigned int height);
    ~Image() = default;

    unsigned int get_width() const;
    unsigned int get_height() const;

    virtual void save_image(const char *file_name) const = 0;

    void clear_image();
    void resize_image(const unsigned int new_width, const unsigned int new_height);

protected:
    unsigned int m_width; // num cols
    unsigned int m_height; // num rows
    BaseMatrix m_matrix;
};

class GrayscaleImage : public Image
{
public:
    GrayscaleImage() = delete;
    GrayscaleImage(const unsigned int width, const unsigned int height);
    ~GrayscaleImage() = default;

    void save_image(const char *file_name) const override;

    void set_pixel(const unsigned int x, const unsigned int y, const GrayscalePixelValue pixel_value);
    void fill_image(const GrayscalePixelValue pixel_value);

private:
    GrayscaleMatrix m_matrix;
};

class RGBImage : public Image
{
public:
    RGBImage() = delete;
    RGBImage(const unsigned int width, const unsigned int height);
    ~RGBImage() = default;

    virtual void save_image(const char *file_name) const override;

    void set_pixel(const unsigned int x, const unsigned int y, const RGBPixelValue pixel_value);
    void fill_image(const RGBPixelValue pixel_value);

private:
    RGBMatrix m_matrix;
};
