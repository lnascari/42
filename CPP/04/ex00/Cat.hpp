#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &c);
	Cat &operator=(const Cat &c);
	~Cat();
	virtual void makeSound() const;
};

#endif