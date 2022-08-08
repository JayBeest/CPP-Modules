#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	orientation;

	orientation = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());

	return orientation * ((b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX())) > 0 &&
		   orientation * ((c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX())) > 0 &&
		   orientation * ((a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX())) > 0;
}

bool	is_triangle(Point const a, Point const b, Point const c)
{
	if (a == b || a == c || b == c)
		return false;
	return true;
}

int main( int argc, char **argv ) {

	if (argc == 2)
	{
		if (std::string(argv[1]) == "-s")
		{
			std::cout << std::endl << "Making [Fixed] silent..." << std::endl << std::endl;
			Fixed::makeSilent();
		}
		else if (std::string(argv[1]) == "-s2")
		{
			std::cout << std::endl << "Making [Fixed] silent..." << std::endl;
			Fixed::makeSilent();
			std::cout << std::endl << "Making [Point] silent..." << std::endl << std::endl;
			Point::makeSilent();
		}
	}

	const Point	a(3.2,5.4);
	const Point	b(2,7);
	const Point	c(1,3);
	const Point p(1.2, 3.5);

	if (!is_triangle(a, b, c))
	{
		std::cout << "Points A, B, and C do not form a triangle ABC" << std::endl;
		return 1;
	}

	if (bsp(a, b, c, p))
		std::cout << "Point(" << p.getX() << ", " << p.getY() <<  ") is inside triangle ABC" << std::endl;
	else
		std::cout << "Point(" << p.getX() << ", " << p.getY() <<  ") is outside triangle ABC" << std::endl;

	return 1;
}
