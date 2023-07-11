#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	n = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->n = n << 8;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->n = roundf(n * 256);
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
	n = f.n;
	return *this;
}

bool &Fixed::operator>(const Fixed &f) const
{
	bool b = n > f.n;
	return b;
}

bool &Fixed::operator<(const Fixed &f) const
{
	bool b = n < f.n;
	return b;
}

bool &Fixed::operator>=(const Fixed &f) const
{
	bool b = n >= f.n;
	return b;
}

bool &Fixed::operator<=(const Fixed &f) const
{
	bool b = n <= f.n;
	return b;
}

bool &Fixed::operator==(const Fixed &f) const
{
	bool b = n == f.n;
	return b;
}

bool &Fixed::operator!=(const Fixed &f) const
{
	bool b = n != f.n;
	return b;
}

Fixed &Fixed::operator+(const Fixed &f) const
{
	Fixed r(this->toFloat() + f.toFloat());
	return r;
}

Fixed &Fixed::operator-(const Fixed &f) const
{
	Fixed r(this->toFloat() - f.toFloat());
	return r;
}

Fixed &Fixed::operator*(const Fixed &f) const
{
	Fixed r(this->toFloat() + f.toFloat());
	return r;
}

Fixed &Fixed::operator/(const Fixed &f) const
{
	Fixed r(this->toFloat() / f.toFloat());
	return r;
}

Fixed &Fixed::operator++()
{
	n++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed r(*this);
	n++;
	return r;
}

Fixed &Fixed::operator--()
{
	n--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed r(*this);
	n--;
	return r;
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
	return n / 256.0;
}

int Fixed::toInt(void) const
{
	return n >> 8;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

Fixed &Fixed::min(Fixed & a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed & a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}