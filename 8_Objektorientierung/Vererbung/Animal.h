#pragma once

#include <string>

class Animal
{
public:
	Animal(std::string &name);
	~Animal() {}
	void type();
	std::string get_name() const;
private:
	std::string m_name;
};