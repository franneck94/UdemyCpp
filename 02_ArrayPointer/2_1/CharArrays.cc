#include <iostream>

int main()
{
    const char first_name[] = {'J', 'a', 'n', '\0'};
    std::cout << first_name << std::endl;

    char last_name[] = "Schaffranek";
    std::cout << last_name << std::endl;

    last_name[0] = 's';

    for (std::uint32_t i = 0; i < sizeof(last_name) - 1U; ++i)
    {
        std::cout << "Char[i] = " << last_name[i] << std::endl;
    }

    return 0;
}
