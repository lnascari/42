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

void PmergeMe::sort()
{
	struct timeval	tv;
	std::cout << "Before:\t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	gettimeofday(&tv, 0);
	int start = tv.tv_usec;
	mergeSort(v, 0, v.size());
	gettimeofday(&tv, 0);
	std::cout << std::endl << "After:\t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}