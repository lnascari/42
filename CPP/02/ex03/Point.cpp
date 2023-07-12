#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point(const float _x, const float _y) : x(Fixed(_x)), y(Fixed(_y)) {}

Point::Point(const Point &p)
{
	*this = p;
}

Point &Point::operator=(const Point &p)
{
	if(this == &p)
       return *this;
	return *this;
}

Point::~Point(){}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}