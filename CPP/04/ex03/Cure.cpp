#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	type = "cure";
}

Cure::Cure(const Cure &c) : AMateria(c)
{
	*this = c;
}

Cure & Cure::operator=(const Cure & c)
{
	(void) c;
	return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const
{
	return new Cure();
}