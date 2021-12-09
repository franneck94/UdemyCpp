#include <iostream>
#include <string>

#include "Animal.h"

int main()
{
    {
        std::string animal_name = "Tatze";
        Animal animal1(animal_name);
    }

    std::cout << std::endl;

    {
        std::string dog_name = "Bello";
        Dog dog1(dog_name);
    }

    return 0;
}
