#include <iostream>
#include <string>

int main()
{
    // Empty String
    {
        auto str = std::string();
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof  : " << size << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
    }
    // Before Threshold String
    {
        auto str = std::string(15, '*');
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof  : " << size << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
    }
    // After Threshold String
    {
        auto str = std::string(16, '*');
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof  : " << size << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
    }

    return 0;
}
