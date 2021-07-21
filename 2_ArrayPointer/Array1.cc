#include <iostream>

// dType varName[numElements]

int main()
{
    int array1[5] = {10, 11, 12, 13, 14};

    std::cout << "Index 0: " << array1[0] << std::endl;
    std::cout << "Index 1: " << array1[1] << std::endl;
    std::cout << "Index 2: " << array1[2] << std::endl;
    std::cout << "Index 3: " << array1[3] << std::endl;
    std::cout << "Index 4: " << array1[4] << std::endl;

    int array2[] = {20, 21, 22};

    std::cout << "Index 0: " << array2[0] << std::endl;
    std::cout << "Index 1: " << array2[1] << std::endl;
    std::cout << "Index 2: " << array2[2] << std::endl;

    return 0;
}
