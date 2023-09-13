#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *m[4];
	int mCount;
public:
	MateriaSource();
	MateriaSource(const MateriaSource &s);
	MateriaSource &operator=(const MateriaSource &s);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const &type);
};

#endif