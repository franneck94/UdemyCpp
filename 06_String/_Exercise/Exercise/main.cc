#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "exercise.h"

int main()
{
    auto iffile = std::ifstream{};
    iffile.open("text.txt", std::ios::in);

    auto content = std::string{};
    iffile >> content;
    iffile.close();

    auto data = ByteArray(8, 0xAA);
    auto key = ByteArray(8, 0xFF);
    const auto cipher_text = hex_vector_xor(data, key);

    for (std::size_t i = 0; i < data.size(); ++i)
    {
        std::cout << "Data[" << i << "] = " << static_cast<int>(data[i])
                  << '\n';
    }
    std::cout << '\n';

    for (std::size_t i = 0; i < cipher_text.size(); ++i)
    {
        std::cout << "Cipher[" << i
                  << "] = " << static_cast<int>(cipher_text[i]) << '\n';
    }
    std::cout << '\n';

    ByteArray message = hex_vector_xor(cipher_text, key);

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        std::cout << "Message[" << i << "] = " << static_cast<int>(message[i])
                  << '\n';
    }
    std::cout << '\n';

    return 0;
}
