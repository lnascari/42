#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T> class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;
	MutantStack() {}
	MutantStack(const MutantStack &m)
	{
		*this = m;
	}
	MutantStack &operator=(const MutantStack &m)
	{
		std::stack<T>::operator=(m);
		return *this;
	}
	~MutantStack() {}
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#endif