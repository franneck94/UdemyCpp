#pragma once

#include "Animal.h"

class Dog: public Animal
{
public:
	Dog(std::string &name, bool &is_pet);
	~Dog() {};
	void type();
private:
	bool m_is_pet;
};