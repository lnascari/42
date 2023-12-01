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
	struct timespec	ts;
	long start;
	std::cout << "Before:\t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_nsec;
	mergeSort(v, 0, v.size());
	clock_gettime(CLOCK_REALTIME, &ts);
	std::cout << std::endl << "After:\t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl << "Time to process a range of " << v.size() << " elements with std::vector:\t" << ts.tv_nsec - start << " ns";
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_nsec;
	mergeSort(d, 0, d.size());
	clock_gettime(CLOCK_REALTIME, &ts);
	std::cout << std::endl << "Time to process a range of " << d.size() << " elements with std::deque:\t" << ts.tv_nsec - start << " ns" << std::endl;
}