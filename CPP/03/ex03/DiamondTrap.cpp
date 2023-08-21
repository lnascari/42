#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "DiamondTrap constructor" << std::endl;
	name = "";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << "DiamondTrap constructor" << std::endl;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d) : ClapTrap(d), ScavTrap(d), FragTrap(d)
{
	*this = d;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &d)
{
	if(this == &d)
       return *this;
	name = d.name;
	hitPoints = d.hitPoints;
	energyPoints = d.energyPoints;
	attackDamage = d.attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << name << " ClapTrap " << ClapTrap::name << std::endl;
}