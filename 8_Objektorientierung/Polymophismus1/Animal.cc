#include <iostream>

#include "Animal.h"

Animal::Animal(std::string &name) :
	m_name(name)
{
	std::cout << "Animal Constructor!" << std::endl;
}

void Animal::type()
{
	std::cout << "Animal!" << std::endl;
}

std::string Animal::get_name() const
{
	return m_name;
}