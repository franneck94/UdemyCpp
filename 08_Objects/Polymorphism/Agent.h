#pragma once

#include <iostream>
#include <string>

class Agent
{
public:
    Agent(const std::string &name, const std::uint32_t id) : m_name(name), m_id(id)
    {
        std::cout << "Agent Constructor!" << std::endl;
    }

    Agent(const std::string &name,
          const std::uint32_t id,
          const std::uint32_t hp,
          const std::uint32_t energy)
        : m_name(name), m_id(id), m_hp(hp), m_energy(energy)
    {
        std::cout << "Agent Constructor!" << std::endl;
    }

    ~Agent()
    {
        std::cout << "Agent Destructor!" << std::endl;
    }

    virtual void print_agent_data()
    {
        std::cout << "Agent hp: " << m_hp << ", energy: " << m_energy << std::endl;
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
        std::cout << "Player Constructor!" << std::endl;
    }

    Player(const std::string &name,
           const std::uint32_t id,
           const std::uint32_t hp,
           const std::uint32_t energy)
        : Agent(name, id, hp, energy)
    {
        std::cout << "Player Constructor!" << std::endl;
    }

    ~Player()
    {
        std::cout << "Player Destructor!" << std::endl;
    }

    void print_agent_data() override
    {
        std::cout << "Player hp: " << m_hp << ", energy: " << m_energy << std::endl;
    }
};

class NPC : public Agent
{
public:
    NPC(const std::string &name, const std::uint32_t id) : Agent(name, id)
    {
        std::cout << "NPC Constructor!" << std::endl;
    }

    NPC(const std::string &name,
        const std::uint32_t id,
        const std::uint32_t hp,
        const std::uint32_t energy)
        : Agent(name, id, hp, energy)
    {
        std::cout << "NPC Constructor!" << std::endl;
    }

    ~NPC()
    {
        std::cout << "NPC Destructor!" << std::endl;
    }

    void print_agent_data() override
    {
        std::cout << "BPC hp: " << m_hp << ", energy: " << m_energy << std::endl;
    }
};
