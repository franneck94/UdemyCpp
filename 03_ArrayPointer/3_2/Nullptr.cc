#include <cstdint>
#include <iostream>

int main()
{
    auto *p = new std::int32_t{4};

    if (p != nullptr)
    {
        std::cout << p << '\n';
        std::cout << *p << '\n';
    }
    else
    {
        std::cout << "p does not own the memory!\n";
    }

    delete p;
    p = nullptr;

    return 0;
}
