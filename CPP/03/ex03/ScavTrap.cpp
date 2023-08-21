#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructor" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap(s)
{
	*this = s;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &s)
{
	if(this == &s)
       return *this;
	name = s.name;
	hitPoints = s.hitPoints;
	energyPoints = s.energyPoints;
	attackDamage = s.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints < 0) {
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
	} else if (!energyPoints) {
		std::cout << "ScavTrap " << name << " can't attack" << std::endl;
	} else {
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage" << std::endl;
		energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is in gate keeper mode" << std::endl;
}