#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
    Animal(const std::string &name) : m_name(name)
    {
        std::cout << "Animal Constructor!" << std::endl;
    }

    ~Animal()
    {
        std::cout << "Animal Destructor!" << std::endl;
    }

    virtual void my_favourite_food()
    {
        std::cout << "Salad" << std::endl;
    }

private:
    const std::string m_name;
};

class Dog : public Animal
{
public:
    Dog(const std::string &name) : Animal(name)
    {
        std::cout << "Dog Constructor!" << std::endl;
    }

    ~Dog()
    {
        std::cout << "Dog Destructor!" << std::endl;
    }

    void my_favourite_food() override
    {
        std::cout << "Meat" << std::endl;
    }
};
