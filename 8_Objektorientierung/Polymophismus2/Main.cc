#include <iostream>
#include <string>

#include "Animal.h"
#include "Dog.h"

void eatingPoly(Animal &animal)
{
	animal.eating();
}

int main()
{
	Animal animal1("Tatze");
	animal1.type();

	std::cout << std::endl;

	Dog dog1("Bello", true);
	dog1.type();

	std::cout << std::endl;

	eatingPoly(animal1);
	eatingPoly(dog1);

	return 0;
}