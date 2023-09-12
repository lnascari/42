#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &c);
	Cat &operator=(const Cat &c);
	virtual ~Cat();
	virtual void makeSound() const;
	virtual std::string getType() const;
	virtual void printIdea(int index);
};

#endif