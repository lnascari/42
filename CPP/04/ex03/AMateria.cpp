#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &m)
{
	*this = m;
}

AMateria &AMateria::operator=(const AMateria &m)
{
	if(this == &m)
		return *this;
	type = m.type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
