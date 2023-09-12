#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	type = "ice";
}

Ice::Ice(const Ice &i) : AMateria(i)
{
	*this = i;
}

Ice & Ice::operator=(const Ice & i)
{
	return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const
{
	return new Ice();
}