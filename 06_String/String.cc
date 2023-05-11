#include <iostream>
#include <string>

int main()
{
    const std::string s = "Hello people!";
    std::cout << s << '\n';

    const auto index = s.find("Hallo");

    if (index != std::string::npos)
    {
        std::cout << "Found substring!\n";
    }
    else
    {
        std::cout << "Did not find substring!\n";
    }

    std::cout << s.empty() << '\n';
    std::cout << s.length() << '\n';

    return 0;
}
