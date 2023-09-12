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
	Animal();
	Animal(const Animal &a);
	Animal &operator=(const Animal &a);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
	virtual void printIdea(int index) = 0;
};

#endif