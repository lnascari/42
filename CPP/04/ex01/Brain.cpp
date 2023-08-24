#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &b)
{
	*this = b;
}

Brain &Brain::operator=(const Brain &b)
{
	if(this == &b)
		return *this;
	
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

std::string Brain::getIdea(int index)
{
	return std::string();
}