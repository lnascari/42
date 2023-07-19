#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int count = 0;
	if ((point.getY() < a.getY()) != (point.getY() < b.getY()) && 
		point.getX() < a.getX() + (point.getY() - a.getY()) / (b.getY() - a.getY()) * (b.getX() - a.getX()))
		count++;
	if ((point.getY() < b.getY()) != (point.getY() < c.getY()) && 
		point.getX() < b.getX() + (point.getY() - b.getY()) / (c.getY() - b.getY()) * (c.getX() - b.getX()))
		count++;
	if ((point.getY() < c.getY()) != (point.getY() < a.getY()) && 
		point.getX() < c.getX() + (point.getY() - c.getY()) / (a.getY() - c.getY()) * (a.getX() - c.getX()))
		count++;
	return (count % 2 == 1);
}