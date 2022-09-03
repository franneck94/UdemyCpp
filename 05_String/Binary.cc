#include <bitset>
#include <cstdint>
#include <iostream>
#include <string>

int main()
{
    auto my_byte1 = std::bitset<8>("00011101");
    auto my_byte2 = std::bitset<8>("10010101");
    std::cout << my_byte1 << '\n';
    std::cout << my_byte2 << '\n';

    std::cout << "AND: " << (my_byte1 & my_byte2) << '\n';
    std::cout << "OR: " << (my_byte1 | my_byte2) << '\n';
    std::cout << "XOR: " << (my_byte1 ^ my_byte2) << '\n';
    std::cout << "NEGATION: " << ~my_byte1 << '\n';

    std::uint8_t v1 = 0x01;
    std::uint8_t v2 = 0xFF;
    std::cout << static_cast<int>(v1) << '\n';
    std::cout << static_cast<int>(v2) << '\n';

    std::cout << "AND: " << (v1 & v2) << '\n';
    std::cout << "OR: " << (v1 | v2) << '\n';
    std::cout << "XOR: " << (v1 ^ v2) << '\n';
    std::cout << "NEGATION: " << ~v1 << '\n';

    return 0;
}
