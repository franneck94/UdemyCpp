#include <iostream>

int main()
{
    char last_name[] = "Schaffranek";
    std::cout << last_name << std::endl;

    int values[]{1, 2, 3};
    for (int i = 0; i < 4; i++)
    {
        std::cout << values[i] << std::endl;
    }

    std::cout << values << std::endl;

    return 0;
}
