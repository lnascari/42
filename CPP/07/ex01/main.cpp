#include <iostream>
#include "iter.hpp"

void toupper(int &c)
{
	if (c >= 'a' && c <= 'z')
		c =- 32;
}

int main( void )
{
	char *str = "	giambaTTistA ;42";
	std::cout << "str: " << str << std::endl;
	iter<char>(str, 18, toupper);
	std::cout << "new str: " << str << std::endl;
}