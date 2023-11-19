#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class Agent
{
public:
    Agent(const std::string &name, const std::uint32_t id)
        : m_name(name), m_id(id)
    {
        std::cout << "Agent Constructor!\n";
    }

    ~Agent()
    {
        std::cout << "Agent Destructor!\n";
    }

protected:
    const std::string m_name;
    const std::uint32_t m_id;
};

class Player : public Agent
{
public:
    Player(const std::string &name, const std::uint32_t id) : Agent(name, id)
    {
        std::cout << "Player Constructor!\n";
    }

    ~Player()
    {
        std::cout << "Player Destructor!\n";
    }

    void print_id()
    {
        std::cout << m_id << '\n';
    }
};

class NPC : public Agent
{
public:
    NPC(const std::string &name, const std::uint32_t id) : Agent(name, id)
    {
        std::cout << "NPC Constructor!\n";
    }

    ~NPC()
    {
        std::cout << "NPC Destructor!\n";
    }
};
