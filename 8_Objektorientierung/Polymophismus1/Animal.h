#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
    Animal(std::string &name) : m_name(name)
    {
        std::cout << "Animal Constructor!" << std::endl;
    }

    ~Animal()
    {
        std::cout << "Animal Destructor!" << std::endl;
    }

    void type()
    {
        std::cout << "Animal!" << std::endl;
    }

    std::string get_name() const
    {
        return m_name;
    }

private:
    std::string m_name;
};

class Dog : public Animal
{
public:
    Dog(std::string &name) : Animal(name)
    {
        std::cout << "Dog Constructor!" << std::endl;
    }

    ~Dog()
    {
        std::cout << "Dog Destructor!" << std::endl;
    }

    void type()
    {
        std::cout << "Dog!" << std::endl;
    }
};