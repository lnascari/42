#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	brain = new Brain();
	brain->setIdea("uiwuiuw", 0);
	brain->setIdea("awaoao", 1);
	brain->setIdea("fofwofoff", 2);
	brain->setIdea("aaooauua", 3);
	brain->setIdea("huauhwahuh", 4);
	brain->setIdea("woufuuw", 5);
	type = "Dog";
}

Dog::Dog(const Dog &d) : Animal(d)
{
	*this = d;
}

Dog &Dog::operator=(const Dog &d)
{
	if (this == &d)
		return *this;
	delete brain;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(d.brain->getIdea(i), i);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Wuf" << std::endl;
}

void Dog::printIdea(int index)
{
	if (index >= 0 && index <= 5)
		std::cout << brain->getIdea(index) << std::endl;
}