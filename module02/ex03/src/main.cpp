#include <iostream>
#include "Fixed.hpp"

#include <iostream>
int main( int argc, char **argv ) {

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << std::endl << "Making silent..." << std::endl << std::endl;
		Fixed::makeSilent();
	}

	Fixed a;
	Fixed c = Fixed(352.390f);
	Fixed d = Fixed(-812.390f);
	Fixed e = Fixed(12.390f);
	Fixed f = Fixed(24.390f);
	Fixed g;

	Fixed const b(Fixed(5.7f) * Fixed(-2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl << std::endl;

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	a = e - f;
	std::cout << "e - f: " << a << std::endl;
	a = d - c;
	std::cout << "d - c: " << a << std::endl;
	a = e - f + c;
	std::cout << "e - f + c: " << a << std::endl;
	a = d / c;
	std::cout << "d / c: " << a << std::endl << std::endl;

	for (int i = 0; i < 256; i++) {
		g++;
		if (!((i + 1) % 8))
			std::cout << "g++(x" << i + 1 << "): " << g << std::endl;
	}

	return 1;
}