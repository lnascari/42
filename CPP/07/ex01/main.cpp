#include <iostream>
#include <string>
#include "iter.hpp"

int main( void )
{
	char str[18] = {'	', 'g', 'i', 'a', 'm', 'b', 'a', 'T', 'T', 'i', 's', 't', 'A', ' ', ';' , '4', '2', 0};
	std::cout << "str: " << str << std::endl;
	iter(str, 17, toupper<char>);
	std::cout << "new str: " << str << std::endl;
}