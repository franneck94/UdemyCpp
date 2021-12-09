#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "exercise.h"

int main()
{
    std::ifstream iffile;
    iffile.open("text.txt", std::ios::in);

    std::string content;
    iffile >> content;
    iffile.close();

    ByteArray plain_text(content.begin(), content.end());
    ByteArray key(8, 0xff);
    ByteArray cipher_text = hex_vector_xor(plain_text, key);

    for (std::size_t i = 0; i < cipher_text.size(); ++i)
    {
        std::cout << "Cipher[" << i << "] = " << cipher_text[i] << std::endl;
    }
    std::cout << std::endl;

    ByteArray message = hex_vector_xor(cipher_text, key);

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        std::cout << "Message[" << i << "] = " << message[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
