#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon _wpn) : wpn(_wpn)
{
    this->name = name;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << wpn.getType() << std::endl;
}