#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int n;
	static const int bsize = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &f);
	Fixed &operator=(const Fixed &f);
	bool operator>(const Fixed &f) const;
	bool operator<(const Fixed &f) const;
	bool operator>=(const Fixed &f) const;
	bool operator<=(const Fixed &f) const;
	bool operator==(const Fixed &f) const;
	bool operator!=(const Fixed &f) const;
	Fixed operator+(const Fixed &f) const;
	Fixed operator-(const Fixed &f) const;
	Fixed operator*(const Fixed &f) const;
	Fixed operator/(const Fixed &f) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif