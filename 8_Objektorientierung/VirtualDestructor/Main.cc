#include <iostream>
#include <string>

#include "Animal.h"

void eatingPoly(Animal &animal)
{
    animal.eating();
}

int main()
{
    std::string name_animal = "Tatze";
    Animal animal1(name_animal);
    animal1.type();

    std::cout << std::endl;

    std::string name_dog = "Bello";
    Dog dog1(name_dog);
    dog1.type();

    std::cout << std::endl;

    eatingPoly(animal1);
    eatingPoly(dog1);

    return 0;
}