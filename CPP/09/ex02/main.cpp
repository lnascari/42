#include "PmergeMe.hpp"
#include <cstdlib>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	int arr[argc - 1];
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if (!isdigit(argv[i][j])) {
				std::cout << "Error" << std::endl;
				return 1;
			}
		}
		arr[i - 1] = atoi(argv[i]);
	}
	std::cout << "Before:\t";
	for (int i = 0; i < argc - 1; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl << "After:\t";
	PmergeMe p(arr, argc - 1);
}