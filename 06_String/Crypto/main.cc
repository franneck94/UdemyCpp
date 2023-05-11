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

    auto plain_text = ByteArray(content.begin(), content.end());
    auto key = ByteArray(8, 0xFF);
    auto cipher_text = hex_vector_xor(plain_text, key);

    for (std::size_t i = 0; i < cipher_text.size(); ++i)
    {
        std::cout << "Cipher[" << i << "] = " << cipher_text[i] << '\n';
    }
    std::cout << '\n';

    auto message = hex_vector_xor(cipher_text, key);

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        std::cout << "Message[" << i << "] = " << message[i] << '\n';
    }
    std::cout << '\n';

    return 0;
}
