#include <iostream>

#include "Weapons.h"

std::string Weapon::get_name() const
{
    return name;
}

float Weapon::get_damage() const
{
    return damage;
}

float Weapon::get_attack_speed() const
{
    return attack_speed;
}

bool Weapon::get_single_handed() const
{
    return single_handed;
}

bool Weapon::get_dual_handed() const
{
    return dual_handed;
}

void Axe::attack()
{
    std::cout << "Attacking with an axe\n";
}

void Longbow::attack()
{
    std::cout << "Attacking with a longbow\n";
}
