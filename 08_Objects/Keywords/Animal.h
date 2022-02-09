#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
    Animal() = default;

    Animal(const std::string &name) : m_name(name)
    {
        std::cout << "Animal Constructor!" << std::endl;
    }

    virtual ~Animal()
    {
        std::cout << "Animal Destructor!" << std::endl;
    }

    virtual void my_favourite_food()
    {
        std::cout << "Salad" << std::endl;
    }

    // virtual void make_a_sound() = 0;

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

    void my_favourite_food() final
    {
        std::cout << "Meat" << std::endl;
    }

    // void make_a_sound() final
    // {
    //     std::cout << "bark!" << std::endl;
    // }
};
