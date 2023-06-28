#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *wpn;
public:
    HumanB(std::string name);
    void setWeapon(Weapon wpn);
    void attack();
};

#endif