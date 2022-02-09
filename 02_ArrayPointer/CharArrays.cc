#include <iostream>

int main()
{
    char fist_name[] = {'J', 'a', 'n', '\0'};

    std::cout << fist_name << std::endl;

    char last_name[] = "Schaffranek";

    std::cout << last_name << std::endl;

    for (int i = 0; i < 11; i++)
    {
        std::cout << "Last Name[i]: " << last_name[i] << std::endl;
    }

    return 0;
}
