#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &d) : Animal(d)
{
	*this = d;
}

Dog &Dog::operator=(const Dog &d)
{
	(void) d;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wuf" << std::endl;
}