#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	n = 0;
}

Fixed::Fixed(const int n)
{
	this->n = n << 8;
}

Fixed::Fixed(const float n)
{
	union bits
	{
		float f;
		unsigned n;
	} u_bits;
	u_bits.f = n;
	bool sign = u_bits.n >> 31;
	int exp = (u_bits.n << 1) >> 24;
	int mant = (u_bits.n << 9) >> 9;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this == &f)
       return *this;
	n = f.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return n;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	n = raw;
}

float Fixed::toFloat(void) const
{
	return 0.0f;
}

int Fixed::toInt(void) const
{
	return 0;
}