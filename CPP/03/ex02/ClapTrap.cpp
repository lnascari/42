#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor" << std::endl;
	name = "";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout << "ClapTrap constructor" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	*this = c;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	if(this == &c)
       return *this;
	name = c.name;
	hitPoints = c.hitPoints;
	energyPoints = c.energyPoints;
	attackDamage = c.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	} else if (!energyPoints) {
		std::cout << "ClapTrap " << name << " can't attack" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage" << std::endl;
		energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " lost " << amount << " life points" << std::endl;
		hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	} else if (!energyPoints) {
		std::cout << "ClapTrap " << name << " can't be repaired" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " restored " << amount << " life points" << std::endl;
		hitPoints += amount;
		energyPoints--;
	}
}