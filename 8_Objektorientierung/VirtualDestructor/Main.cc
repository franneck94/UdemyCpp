#include <iostream>
#include <string>

#include "Animal.h"
#include "Dog.h"

void eatingPoly(Animal* &animal)
{
	animal->eating();
}

int main()
{
	Animal* animal1 = new Animal("Tatze");
	animal1->type();
	std::cout << std::endl;

	Animal* dog1 = new Dog("Bello", true);
	dog1->type();
	std::cout << std::endl;

	eatingPoly(animal1);
	eatingPoly(dog1);
	std::cout << std::endl;

	delete animal1;
	std::cout << std::endl;
	delete dog1;

	return 0;
}