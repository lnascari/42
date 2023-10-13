#include "Character.hpp"

Character::Character(std::string name)
{
	std::cout << "Character constructor" << std::endl;
	this->name = name;
	nItems = 0;
}

Character::Character(const Character &c)
{
	*this = c;
}

Character &Character::operator=(const Character &c)
{
	if (this == &c)
		return *this;
	for (int i = 0; i < nItems; i++)
		delete inventory[i];
	name = c.name;
	nItems = c.nItems;
	for (int i = 0; i < c.nItems; i++)
		inventory[i] = c.inventory[i];
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < nItems; i++)
		delete inventory[i];
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (nItems != 4 && m)
		inventory[nItems++] = m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < nItems) {
		for (int i = idx + 1; i < nItems; i++)
			inventory[i - 1] = inventory[i];
		nItems--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < nItems)
		inventory[idx]->use(target);
}