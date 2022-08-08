#include <iostream>
#include "Point.hpp"

///			Public:

///			Getters/Setters

const Fixed &	Point::getX( ) const {

	return this->x;
}

const Fixed &	Point::getY( ) const {

	return this->y;
}

///			Constructor/Destroyer

Point::Point( const float x, const float y ) : x(Fixed(x)), y(Fixed(y)) {

}

Point::Point( ) : x(0), y(0) {

}

Point::Point( const Point& other) {

		*this = other;
}

Point::~Point( ) {

}

Point &	Point::operator=( const Point& rhs ) {

	if (this != &rhs)
		std::cout << "Copy assignment operator cannot assign 'const Fixed x, y" << std::endl;
	return *this;
}

///			Functions/Methods

void	Point::doStuff( ) const {

	// TODO

}

///			Private:

