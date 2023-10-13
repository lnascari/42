#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor" << std::endl;
	type = "ice";
}

Ice::Ice(const Ice &i) : AMateria(i)
{
	*this = i;
}

Ice & Ice::operator=(const Ice & i)
{
	(void) i;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice();
}