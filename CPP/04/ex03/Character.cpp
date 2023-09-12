#include "Character.hpp"

Character::Character(std::string name)
{
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
	for (size_t i = 0; i < nItems; i++)
		delete inventory[i];
	name = c.name;
	nItems = c.nItems;
	for (size_t i = 0; i < c.nItems; i++)
		inventory[i] = c.inventory[i];
	return *this;
}

Character::~Character() {
	for (size_t i = 0; i < nItems; i++)
		delete inventory[i];
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (nItems != 4)
		inventory[nItems++] = m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < nItems) {
		for (size_t i = idx + 1; i < nItems; i++)
			inventory[i - 1] = inventory[i];
		nItems--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < nItems)
		inventory[idx]->use(target);
}