#include <iostream>
#include <string>

#include "Animal.h"

void polyFavouriteFood(Animal &animal)
{
    animal.my_favourite_food();
}

int main()
{
    {
        std::string animal_name = "Tatze";
        Animal animal1(animal_name);
        polyFavouriteFood(animal1);
    }

    std::cout << std::endl;

    {
        std::string dog_name = "Bello";
        Dog dog1(dog_name);
        polyFavouriteFood(dog1);
    }

    return 0;
}
