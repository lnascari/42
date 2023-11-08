#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T> void toupper(T &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int main( void )
{
	char str[18] = {'	', 'g', 'i', 'a', 'm', 'b', 'a', 'T', 'T', 'i', 's', 't', 'A', ' ', ';' , '4', '2', 0};
	std::cout << "str: " << str << std::endl;
	iter(str, 17, toupper);
	std::cout << "new str: " << str << std::endl;
}