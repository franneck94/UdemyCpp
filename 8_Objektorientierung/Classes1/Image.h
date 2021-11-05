class Image
{
public:
    // Konstruktor
    Image();
    Image(const unsigned int &width, const unsigned int &height);

    // Destruktor
    ~Image();

private:
    unsigned int m_width;
    unsigned int m_height;
};
