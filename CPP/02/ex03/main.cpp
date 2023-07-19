#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(1.5454, 3.234);
	Point b(6.346, 1.4325);
	Point c(5.8622, 6.2489);
	Point p(6.123, 5.743);
	std::cout << bsp(a, b, c, p) << std::endl;
}