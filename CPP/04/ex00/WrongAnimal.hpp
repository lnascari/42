#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string.h>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &a);
	WrongAnimal &operator=(const WrongAnimal &a);
	~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};

#endif