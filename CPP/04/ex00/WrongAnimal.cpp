#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor" << std::endl;
	type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	*this = a;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	(void) a;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}