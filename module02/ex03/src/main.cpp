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

void	test() {

	const Point	a(0, 0);
	const Point	b(0, 5);
	const Point	c(4, 0);

	check_bsp(Point(-1, 0), a, b, c);
	check_bsp(Point(1, 0), a, b, c);
	check_bsp(Point(1, -1), a, b, c);
	check_bsp(Point(1, 4), a, b, c);
	check_bsp(Point(5, 1), a, b, c);
	check_bsp(Point(1, 1), a, b, c);
	check_bsp(Point(2, 2), a, b, c);
	check_bsp(Point(1, 3), a, b, c);
	check_bsp(Point(0.123, 3.812), a, b, c);
}

int main( int argc, char **argv ) {

	if (argc == 2)
	{
		if (std::string(argv[1]) == "-s")
		{
			std::cout << std::endl << "Making [Fixed] silent...(use -s2 to also silence [Point])" << std::endl << std::endl;
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
	
	check_bsp(p, a, b, c);
	
	test();

	return 1;
}
