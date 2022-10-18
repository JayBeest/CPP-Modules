#include <iostream>
#include "iter.hpp"
#include "Fixed.hpp"

int	main(void) {

//	Fixed::makeSilent();

	int	intArray[5] = {0,0,0,0,0};

	::iter(intArray, 5, ::printElement);
	::iter(intArray, 5, plusPlus);
	::iter(intArray, 5, ::printElement);

	std::string	stringArray[5] = {"een", "twee", "drie", "vier", "vijf"};

	::iter(stringArray, 5, ::printElement);
	::iter(stringArray, 5, plusPlus);
	::iter(stringArray, 5, ::printElement);

	Fixed	fixedArray[3] = {4, 5, 6};
	::iter(fixedArray, 3, ::printElement);
	::iter(fixedArray, 3, ::plusPlus);
	::iter(fixedArray, 3, ::printElement);

	// TODO MOAR TESTING!!!!!!!!!!!!

	// TODO ask on slack to get permission to add Fixed.cpp/hpp from mod02 ex02 for testing purposes

	return 0;
}
