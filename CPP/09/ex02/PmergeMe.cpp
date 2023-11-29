#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int arr[], int size)
{
	std::vector<int> _v(arr, arr + size);
	v = _v;
	std::deque<int> _d(arr, arr + size);
	d = _d;
}

PmergeMe::PmergeMe(const PmergeMe &p)
{
	*this = p;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &p)
{
	if (this == &p)
		return *this;
	v = p.v;
	d = p.d;
	return *this;
}

PmergeMe::~PmergeMe() {}