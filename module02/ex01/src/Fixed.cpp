#include <cmath>
#include "Fixed.hpp"

///			Public:

int		Fixed::getRawBits( void ) const {

	return this->_fixed_point;
}

void		Fixed::setRawBits( const int & raw ) {

	this->_fixed_point = raw;
}

///			Constructor/Destructor

Fixed::Fixed( ) : _fixed_point(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int & int_value ) {

	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(int_value << _fractional_bits);
}

Fixed::Fixed( const float & float_value ) : _fixed_point(0) {

	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_value * (1 << _fractional_bits)));
}

Fixed::Fixed( const Fixed & other ) {

	std::cout << "Copy constructor called" << std::endl;
    if (this != &other)
    {
	    *this = other;
    }
}

Fixed::~Fixed( ) {

	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( const Fixed & rhs ) {

	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
	    this->setRawBits(rhs.getRawBits());
    }
	return *this;
}

///			Functions/Methods

float	Fixed::toFloat( void ) const {

	return ((float)this->getRawBits() / (1 << (Fixed::_fractional_bits)));
}

int		Fixed::toInt( void ) const {

	return this->_fixed_point >> _fractional_bits;
}

///			Private:

std::ostream &	operator<<( std::ostream & o_stream, Fixed const & fix ) {

	return o_stream << fix.toFloat();
}

int	const Fixed::_fractional_bits = 8;
