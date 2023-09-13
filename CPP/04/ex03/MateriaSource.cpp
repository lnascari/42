#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	mCount = 0;
}

MateriaSource::MateriaSource(const MateriaSource &s)
{
	*this = s;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &s)
{
	if (this == &s)
		return *this;
	for (int i = 0; i < mCount; i++)
		delete m[i];
	mCount = s.mCount;
	for (int i = 0; i < s.mCount; i++)
		m[i] = s.m[i];
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < mCount; i++)
		delete m[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (mCount != 4)
		this->m[mCount++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < mCount; i++) {
		if (m[i]->getType() == type)
			return m[i]->clone();
	}
	return 0;
}