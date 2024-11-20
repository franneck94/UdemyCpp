#include <cstdint>
#include <iostream>

std::uint32_t sum(std::uint32_t n)
{

}

int main()
{
    std::uint32_t n = 10; // 0..10
    std::uint32_t s = sum(n);

    std::cout << "Sum from 0..10: " << s << std::endl;

    return 0;
}
