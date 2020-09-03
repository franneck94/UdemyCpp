#include <iostream>

int main()
{
    // sizeof()
    char a = 10000000000000;
    short b = 200000000000000000;
    int c = 3000000000000;
    long long int d = 4000000000000;
    float e = 5000000.0;
    double f = 6000000000000.0;

    std::cout << "Char memory size in Bytes: " << sizeof(a) << std::endl;
    std::cout << "Short memory size in Bytes: " << sizeof(b) << std::endl;
    std::cout << "Integer memory size in Bytes: " << sizeof(c) << std::endl;
    std::cout << "Long memory size in Bytes: " << sizeof(d) << std::endl;
    std::cout << "Float memory size in Bytes: " << sizeof(e) << std::endl;
    std::cout << "Double memory size in Bytes: " << sizeof(f) << std::endl;

    return 0;
}