#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T> bool easyfind(T arr, int n)
{
	if (std::find(arr.begin(), arr.end(), n) != arr.end())
		return true;
	return false;
}

#endif