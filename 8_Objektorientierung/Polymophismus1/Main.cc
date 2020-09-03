#include <iostream>
#include <string>

#include "Animal.h"
#include "Dog.h"

int main()
{
    std::string name_animal = "Tatze";
    Animal animal1(name_animal);
    animal1.type();

    std::cout << std::endl;

    std::string name_dog = "Bello";
    bool type_dog = true;
    Dog dog1(name_dog, type_dog);
    dog1.type();

    std::cout << std::endl;

    return 0;
}