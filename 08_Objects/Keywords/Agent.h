#pragma once

#include <iostream>
#include <string>

class Agent
{
public:
    Agent() = default;

    Agent(const std::string &name) : m_name(name)
    {
        std::cout << "Agent Constructor!" << '\n';
    }

    virtual ~Agent()
    {
        std::cout << "Agent Destructor!" << '\n';
    }

    virtual void my_favourite_food()
    {
        std::cout << "Salad" << '\n';
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
        std::cout << "Player Constructor!" << '\n';
    }

    ~Player()
    {
        std::cout << "Player Destructor!" << '\n';
    }

    void my_favourite_food() final
    {
        std::cout << "Meat" << '\n';
    }

    // void make_a_sound() final
    // {
    //     std::cout << "bark!" << '\n';
    // }
};
