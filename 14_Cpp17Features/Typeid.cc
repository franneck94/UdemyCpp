#include <iostream>
#include <typeindex>
#include <typeinfo>


int main()
{
    int a = 1;
    float b = 1.0f;
    char c = 'a';
    char d = 'b';

    std::cout << "Type a: " << typeid(a).name() << std::endl;
    std::cout << "Type b: " << typeid(b).name() << std::endl;
    std::cout << "Type c: " << typeid(c).name() << std::endl;

    // 12638219084838855839
    // 12638217985327228012
    if (typeid(c).hash_code() == typeid(d).hash_code())
    {
        std::cout << typeid(c).hash_code() << " " << typeid(c).name() << std::endl;
    }
    else
    {
        std::cout << typeid(d).hash_code() << " " << typeid(d).name() << std::endl;
    }

    return 0;
}