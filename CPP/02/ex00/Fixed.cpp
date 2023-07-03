#include "Fixed.hpp"

Fixed::Fixed()
{
	n = 0;
}

Fixed::Fixed(const Fixed &f)
{
	n = f.n;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if(this == &f)
       return *this;
	n = f.n;
	return *this;
}

Fixed::~Fixed()
{
}