#include <cstdint>
#include <iostream>

int main()
{
    auto *p = new std::int32_t{4};

    if (p != nullptr)
    {
        std::cout << p << std::endl;
        std::cout << *p << std::endl;
    }
    else
    {
        std::cout << "p does not own the memory!\n";
    }

    delete p;
    p = nullptr;

    return 0;
}
