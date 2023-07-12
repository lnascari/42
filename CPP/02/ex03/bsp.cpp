#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed res = a.getX() * (b.getY() - c.getY()) + a.getX() * (b.getY() - c.getY()) + a.getX() * (b.getY() - c.getY());
	return (res.toFloat() < 0) ? res / Fixed(-2) : res / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = area(a, b, c); 
	Fixed pbc = area(point, b, c);
	Fixed apc = area(a, point, c);
	Fixed abp = area(a, b, point);
	std::cout << abc << " " << pbc << " " << abp << " ";
	return (abc == pbc + apc + abp);
}