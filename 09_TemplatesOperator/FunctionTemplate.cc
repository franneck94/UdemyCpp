#include <iostream>

template <typename T>
T max(const T &a, const T &b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    std::cout << max(10, 11) << std::endl;
    std::cout << max(10.0F, 11.0F) << std::endl;
    std::cout << max(10.0, 11.0) << std::endl;

    std::cout << max<short>(10, 11) << std::endl;

    return 0;
}
