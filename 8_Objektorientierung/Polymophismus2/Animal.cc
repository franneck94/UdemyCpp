#include <iostream>

#include "Animal.h"

Animal::Animal(const std::string &name) :
	m_name(name)
{
	std::cout << "Animal Constructor!" << std::endl;
}

void Animal::type() const
{
	std::cout << "Animal!" << std::endl;
}

void Animal::eating() const
{
	std::cout << "I am an animal and im hungry, i want to eat!!!" << std::endl;
}

std::string Animal::get_name() const
{
	return m_name;
}