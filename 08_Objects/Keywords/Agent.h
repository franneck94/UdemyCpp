#pragma once

#include <iostream>
#include <string>

class Agent
{
public:
    Agent() = default;

    Agent(const std::string &name) : m_name(name)
    {
        std::cout << "Agent Constructor!" << std::endl;
    }

    virtual ~Agent()
    {
        std::cout << "Agent Destructor!" << std::endl;
    }

    virtual void my_favourite_food()
    {
        std::cout << "Salad" << std::endl;
    }

    // virtual void make_a_sound() = 0;

private:
    const std::string m_name;
};

class Player : public Agent
{
public:
    Player(const std::string &name) : Agent(name)
    {
        std::cout << "Player Constructor!" << std::endl;
    }

    ~Player()
    {
        std::cout << "Player Destructor!" << std::endl;
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
