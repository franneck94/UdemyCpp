#include <iostream>
#include <string>

int main()
{
    std::string s = "Hallo das ist ein Text";

    std::size_t index = s.find("Hallo");

    if (index != std::string::npos)
    {
        std::cout << "Substring found at index " << index << std::endl;
    }
    else
    {
        std::cout << "Substring not found!" << std::endl;
    }

    return 0;
}
