#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[4];
	int nItems;
public:
	Character(std::string name);
	Character(const Character &c);
	Character &operator=(const Character &c);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};


#endif