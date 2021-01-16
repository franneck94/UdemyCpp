#include <iostream>
#include <string>

int main()
{
    std::string text = "Hallo mein Name ist Jan.";

    if (const auto idx = text.find("Jan"); idx != std::string::npos)
    {
        std::cout << "Found Jan" << std::endl;
    }

    if (const auto idx = text.find("Name"); idx != std::string::npos)
    {
        std::cout << "Found Name" << std::endl;
    }

    return 0;
}
