#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria *tmp;
	AMateria *tmp1;
	AMateria *tmp2;
	AMateria *tmp3;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp = src->createMateria("giambattista");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(-4, *bob);
	me->use(18, *bob);
	Character *franco = new Character("franco");
	tmp2 = src->createMateria("cure");
	franco->equip(tmp2);
	tmp3 = src->createMateria("ice");
	franco->equip(tmp3);
	tmp = src->createMateria("earth");
	franco->equip(tmp);
	Character *franco_copy = new Character(*franco);
	franco->unequip(0);
	franco_copy->unequip(1);
	tmp = src->createMateria("cure");
	franco_copy->equip(tmp);
	tmp = src->createMateria("ice");
	franco_copy->equip(tmp);
	franco->use(0, *bob);
	franco->use(1, *bob);
	franco->use(2, *bob);
	franco->use(3, *bob);
	franco_copy->use(0, *bob);
	franco_copy->use(1, *bob);
	franco_copy->use(2, *bob);
	franco_copy->use(3, *bob);
	me->unequip(-1);
	me->unequip(18);
	me->unequip(3);
	me->use(1, *franco);
	me->unequip(1);
	me->use(1, *franco);
	delete bob;
	delete me;
	delete src;
	delete franco;
	delete franco_copy;
	delete tmp1;
}