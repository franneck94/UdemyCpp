#include <iostream>
#include <string>

int main()
{
    for (std::string text = "Jan."; const auto &c : text)
    {
        std::cout << c << " ";
    }

    return 0;
}
