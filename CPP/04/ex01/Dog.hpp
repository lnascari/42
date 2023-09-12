#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &d);
	Dog &operator=(const Dog &d);
	virtual ~Dog();
	virtual void makeSound() const;
	virtual void printIdea(int index);
};

#endif