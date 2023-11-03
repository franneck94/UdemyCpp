#include <iostream>
#include <string>

bool is_palindrom(...)
{
}

int main()
{
    const auto text = std::string{"anna"};
    const auto check = is_palindrom(text);

    std::cout << "Is Palindrom: " << std::boolalpha << check << '\n';

    return 0;
}
