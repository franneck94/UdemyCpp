#include <iostream>
#include <string>

bool is_palindrom(std::string_view text)
{
    const auto reversed = std::string(text.rbegin(), text.rend());

    return text == reversed;
}

int main()
{
    const auto text = std::string{"anna"};
    const auto check = is_palindrom(text);

    std::cout << "Is Palindrom: " << std::boolalpha << check << '\n';

    return 0;
}
