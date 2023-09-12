#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &c);
	Cure &operator=(const Cure &c);
	virtual ~Cure();
	virtual AMateria* clone() const;
};

#endif