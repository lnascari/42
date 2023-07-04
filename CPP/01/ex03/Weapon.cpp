#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType()
{
    std::string& ref = type;
    return ref;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}