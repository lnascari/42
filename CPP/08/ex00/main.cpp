#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	int arr[6] = {3, 6, 7, 4, 1, 2};
	std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::cout << easyfind(l, 4) << std::endl;
	std::cout << easyfind(v, 2) << std::endl;
	std::cout << easyfind(l, 0) << std::endl;
}