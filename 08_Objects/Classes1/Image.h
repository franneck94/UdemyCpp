class Image
{
public:
    // Konstruktor
    Image();
    Image(const unsigned int &width, const unsigned int &height);

    // Destructor
    ~Image();

private:
    unsigned int m_width;
    unsigned int m_height;
};
