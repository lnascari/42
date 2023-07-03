#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int n;
	static const int bsize = 8;
public:
	Fixed();
	Fixed(const Fixed& f);
	Fixed& operator=(const Fixed& f);
	~Fixed();
};

#endif