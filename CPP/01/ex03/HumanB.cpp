#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    wpn = 0;
}

void HumanB::setWeapon(Weapon wpn)
{
    this->wpn = &wpn;
}

void HumanB::attack()
{
    if (wpn)
        std::cout << name << " attacks with their " << (*wpn).getType() << std::endl;
    else
        std::cout << name << " attacks" << std::endl;
}