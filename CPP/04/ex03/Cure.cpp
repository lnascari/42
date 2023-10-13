#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor" << std::endl;
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

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure();
}