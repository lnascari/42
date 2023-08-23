#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &c) : Animal(c)
{
	*this = c;
}

Cat &Cat::operator=(const Cat &c)
{
	(void) c;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Mao" << std::endl;
}