#include "Point.hpp"

void	print_bsp(const Point & p, const std::string & place ,const Point & a, const Point & b, const Point & c)
{
	if (place == "no")
	{
		std::cout << "Points A, B, and C do not form a triangle ABC (" \
            << a.getX() << "," << a.getY() << "   " \
            << b.getX() << "," << b.getY() << "   " \
            << c.getX() << "," << c.getY() << ")" << std::endl
			<< std::endl;
	}
	else
	{
	std::cout << "Point(" << p.getX() << ", " << p.getY() <<  ") is " << place << " triangle ABC (" \
            << a.getX() << ", " << a.getY() << "   " \
            << b.getX() << ", " << b.getY() << "   " \
            << c.getX() << ", " << c.getY() << ")" << std::endl
			<< std::endl;
	}
}

bool	is_triangle(const Point & a, const Point & b, const Point & c)
{
	if (a == b || a == c || b == c)
		return false;
	return true;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	orientation;

	orientation = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());

	return orientation * ((b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX())) > Fixed(0) &&
		   orientation * ((c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX())) > Fixed(0) &&
		   orientation * ((a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX())) > Fixed(0);
}

void	check_bsp(const Point & p, const Point & a, const Point & b, const Point & c)
{
	if (!is_triangle(a, b, c))
	{
		print_bsp(p, "no", a, b, c);
		return;
	}
	if (bsp(a, b, c, p))
    {
		print_bsp(p, "inside", a, b, c);
    }
	else
    {
		print_bsp(p, "outside", a, b, c);
    }
}
