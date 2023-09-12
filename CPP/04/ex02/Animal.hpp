#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;
	Brain *brain;
public:
	virtual void makeSound() const = 0;
	virtual std::string getType() const = 0;
	virtual void printIdea(int index) = 0;
};

#endif