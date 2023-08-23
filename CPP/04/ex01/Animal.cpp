#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor" << std::endl;
	type = "";
}

Animal::Animal(const Animal &a)
{
	*this = a;
}

Animal &Animal::operator=(const Animal &a)
{
	(void) a;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << std::endl;
}

std::string Animal::getType() const
{
	return type;
}