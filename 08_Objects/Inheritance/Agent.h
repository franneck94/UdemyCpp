#pragma once

#include <iostream>
#include <string>

class Agent
{
public:
    Agent(const std::string &name, const std::uint32_t id) : m_name(name), m_id(id)
    {
        std::cout << "Agent Constructor!" << '\n';
    }

    Agent(const std::string &name,
          const std::uint32_t id,
          const std::uint32_t hp,
          const std::uint32_t energy)
        : m_name(name), m_id(id), m_hp(hp), m_energy(energy)
    {
        std::cout << "Agent Constructor!" << '\n';
    }

    ~Agent()
    {
        std::cout << "Agent Destructor!" << '\n';
    }

protected:
    const std::string m_name;
    const std::uint32_t m_id;
    std::uint32_t m_hp = 0U;
    std::uint32_t m_energy = 0U;
};

class Player : public Agent
{
public:
    Player(const std::string &name, const std::uint32_t id) : Agent(name, id)
    {
        std::cout << "Player Constructor!" << '\n';
    }

    Player(const std::string &name,
           const std::uint32_t id,
           const std::uint32_t hp,
           const std::uint32_t energy)
        : Agent(name, id, hp, energy)
    {
        std::cout << "Player Constructor!" << '\n';
    }

    ~Player()
    {
        std::cout << "Player Destructor!" << '\n';
    }
};

class NPC : public Agent
{
public:
    NPC(const std::string &name, const std::uint32_t id) : Agent(name, id)
    {
        std::cout << "NPC Constructor!" << '\n';
    }

    NPC(const std::string &name,
        const std::uint32_t id,
        const std::uint32_t hp,
        const std::uint32_t energy)
        : Agent(name, id, hp, energy)
    {
        std::cout << "NPC Constructor!" << '\n';
    }

    ~NPC()
    {
        std::cout << "NPC Destructor!" << '\n';
    }
};
