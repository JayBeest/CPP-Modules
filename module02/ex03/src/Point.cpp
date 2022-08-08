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

void	Point::makeSilent( ) {

	Point::_loud = false;
}

///			Constructor/Destroyer

Point::Point( const float x, const float y ) : x(Fixed(x)), y(Fixed(y)) {

	if (Point::_loud)
		std::cout << "[Point] Standard constructor called" << std::endl;
}

Point::Point( ) : x(Fixed()), y(Fixed()) {

	if (Point::_loud)
		std::cout << "[Point] Default constructor called" << std::endl;
}

Point::Point( const Point& other)
: x(Fixed(other.getX().toFloat())), y(Fixed(other.getY().toFloat())) {

	if (Point::_loud)
		std::cout << "[Point] Copy constructor called" << std::endl;
//	*this = other;
}

Point::~Point( ) {

	if (Point::_loud)
		std::cout << "[Point] Destructor called" << std::endl;

}

Point &	Point::operator=( const Point & rhs ) {

	if (this != &rhs)
		if (Point::_loud)
			std::cout << "[Point] Copy assignment operator cannot assign (copy) 'const Fixed x, y'" << std::endl;
	return *this;
}

bool	Point::operator==( const Point & rhs ) const {

	return this->getX() == rhs.getX() && this->getY() == rhs.getY();
}

///			Functions/Methods

void	Point::doStuff( ) const {

	// TODO

}

///			Private:

bool	Point::_loud = true;
