#include "Point.hpp"

void	check_bsp(const Point & p, const Point & a, const Point & b, const Point & c);

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
