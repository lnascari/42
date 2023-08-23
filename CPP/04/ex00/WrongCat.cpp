#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &c) : WrongAnimal(c)
{
	*this = c;
}

WrongCat &WrongCat::operator=(const WrongCat &c)
{
	(void) c;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Mao" << std::endl;
}