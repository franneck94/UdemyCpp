#include <iostream>
#include <string>

int main()
{
    for (std::string text = "Jan."; const auto &c : text)
    {
        std::cout << c << " ";
    }

    if (std::string text = "Jan."; text.size() > 2)
    {
        std::cout << "YES\n";
    }

    return 0;
}
