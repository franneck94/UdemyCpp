#include <iostream>

#include "Dog.h"

Dog::Dog(std::string &name, bool &is_pet) : Animal(name), m_is_pet(is_pet)
{
    std::cout << "Dog Constructor!" << std::endl;
}

void Dog::type()
{
    std::cout << "Pet!" << std::endl;
}