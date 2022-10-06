#include "Fixed.hpp"

///			Public:

int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point;
}

void		Fixed::setRawBits( const int & raw ) {

	this->_fixed_point = raw;
}

///			Constructor/Destructor

Fixed::Fixed( ) : _fixed_point(0) {

	std::cout << "Default constructor called" << std::endl;
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

///			Private:

int	const Fixed::_fractional_bits = 8;
