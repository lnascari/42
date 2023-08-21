#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f)
{
	*this = f;
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
	if(this == &f)
       return *this;
	name = f.name;
	hitPoints = f.hitPoints;
	energyPoints = f.energyPoints;
	attackDamage = f.attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (hitPoints <= 0) {
		std::cout << "FragTrap " << name << " is dead" << std::endl;
	} else if (!energyPoints) {
		std::cout << "FragTrap " << name << " can't attack" << std::endl;
	} else {
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage" << std::endl;
		energyPoints--;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " gives high five" << std::endl;
}