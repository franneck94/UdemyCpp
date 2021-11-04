#include <iostream>

int main()
{
    float vector1[3]{};
    float vector2[3]{};

    std::cout << "Enter values for vector 1: " << std::endl;

    for (unsigned int i = 0; i < 3; i++)
    {
        std::cin >> vector1[i];
    }

    std::cout << "Enter values for vector 2: " << std::endl;

    for (unsigned int i = 0; i < 3; i++)
    {
        std::cin >> vector2[i];
    }

    for (unsigned int i = 0; i < 3; i++)
    {
        std::cout << "v1[i] + v2[i] = " << vector1[i] + vector2[i] << std::endl;
    }

    return 0;
}
