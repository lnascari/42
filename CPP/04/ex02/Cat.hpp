#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &c);
	Cat &operator=(const Cat &c);
	virtual ~Cat();
	virtual void makeSound() const;
	virtual void printIdea(int index);
};

#endif