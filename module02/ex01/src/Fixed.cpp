#include <iostream>
#include "Fixed.hpp"
#include <math.h>

///			Public:

int		Fixed::getRawBits( ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point;
}

void		Fixed::setRawBits( const int raw ) {

	this->_fixed_point = raw;
}

///			Constructor/Destructor

Fixed::Fixed( ) : _fixed_point(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int int_value ) {

	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(int_value << _fractional_bits);
}

Fixed::Fixed( const float float_value) : _fixed_point(0) {

	int		whole;
	float	fractional;

	whole = (int)float_value;
	fractional = float_value - (float)whole;
	this->setRawBits((whole << _fractional_bits) + (int)roundf((fractional * (1 << _fractional_bits))));
	std::cout << "Float constructor called" << std::endl;

}

Fixed::Fixed( const Fixed& other) {

	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed( ) {

	std::cout << "Destructor called" << std::endl;

}

Fixed &	Fixed::operator=( const Fixed& rhs ) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return *this;
}

///			Functions/Methods

float	Fixed::toFloat( void ) const {

	int 	shift;

	shift = _fixed_point << (sizeof(int) * 8 - _fractional_bits);
	shift >>= (sizeof(int) * 8 - _fractional_bits);

	return ((float)(_fixed_point >> _fractional_bits) + (float)(shift) / (1 << (_fractional_bits)));
}

int		Fixed::toInt( void ) const {

	return this->_fixed_point >> _fractional_bits;

}

///			Private:

int	const Fixed::_fractional_bits = 8;

std::ostream & operator<<(std::ostream & o_stream, Fixed const & fix) {

	return o_stream << fix.toFloat();
}
