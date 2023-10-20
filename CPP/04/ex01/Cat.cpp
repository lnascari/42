#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	brain = new Brain();
	brain->setIdea("mmmma", 0);
	brain->setIdea("imimamim", 1);
	brain->setIdea("omomommo", 2);
	brain->setIdea("aomaoao", 3);
	brain->setIdea("momomomom", 4);
	brain->setIdea("aaaaaam", 5);
	type = "Cat";
}

Cat::Cat(const Cat &c) : Animal(c)
{
	*this = c;
}

Cat &Cat::operator=(const Cat &c)
{
	if (this == &c)
		return *this;
	delete brain;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(c.brain->getIdea(i), i);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Mao" << std::endl;
}

void Cat::printIdea(int index)
{
	if (index >= 0 && index <= 5)
		std::cout << brain->getIdea(index) << std::endl;
}