#include "Fixed.hpp"
#include <cmath>

///			Public:

int		Fixed::getRawBits( void ) const {

	return this->_fixed_point;
}

void		Fixed::setRawBits( const int & raw ) {

	this->_fixed_point = raw;
}

void	Fixed::makeSilent( void ) {

	Fixed::_loud = false;
}


///			Constructor / Destructor

Fixed::Fixed( ) : _fixed_point(0) {

	if (_loud)
	{
		std::cout << "[Fixed] Default constructor called" << std::endl;
	}
}

Fixed::Fixed( const int & int_value ) {

	if (_loud)
	{
		std::cout << "[Fixed] Int constructor called" << std::endl;
	}
	this->setRawBits(int_value << _fractional_bits);
}

Fixed::Fixed( const float & float_value ) : _fixed_point(0) {

	if (_loud)
    {
        std::cout << "[Fixed] Float constructor called" << std::endl;
    }
	int		integer = (int)float_value;;
	float	fractional = float_value - (float)integer;
	if (float_value != 0)
    {
		this->setRawBits((integer << _fractional_bits) + (int)round((fractional * (1 << _fractional_bits))));
    }
	else
    {
        this->setRawBits(0);
    }
}

Fixed::Fixed( const Fixed & other ) {

	if (_loud)
    {
        std::cout << "[Fixed] Copy constructor called" << std::endl;
    }
    if (this != &other)
    {
	    *this = other;
    }
}

Fixed::~Fixed( ) {

	if (_loud)
    {
		std::cout << "[Fixed] Destructor called" << std::endl;
    }
}

Fixed &	Fixed::operator=( const Fixed & rhs ) {

	if (_loud)
    {
		std::cout << "[Fixed] Copy assignment operator called" << std::endl;
    }
    if (this != &rhs)
    {
	    this->setRawBits(rhs.getRawBits());
    }
	return *this;
}


///			Comparison operators

bool 	Fixed::operator>( const Fixed & rhs ) const {

	if (_loud)
    {
		std::cout << "[Fixed] Larger-than operator called" << std::endl;
    }
	return getRawBits() > rhs.getRawBits();
}

bool 	Fixed::operator>=( const Fixed & rhs ) const {

	if (_loud)
    {
		std::cout << "[Fixed] Larger-than-or-equal-to operator called" << std::endl;
    }
	return getRawBits() >= rhs.getRawBits();
}

bool 	Fixed::operator<( const Fixed & rhs ) const {

	if (_loud)
    {
		std::cout << "[Fixed] Smaller-than operator called" << std::endl;
    }
	return getRawBits() < rhs.getRawBits();
}

bool 	Fixed::operator<=( const Fixed & rhs ) const {

	if (_loud)
    {
		std::cout << "[Fixed] Smaller-than-or-equal-to operator called" << std::endl;
    }
	return getRawBits() <= rhs.getRawBits();
}

bool 	Fixed::operator==( const Fixed & rhs ) const {

	if (_loud)
    {
		std::cout << "[Fixed] Is-equal operator called" << std::endl;
    }
	return getRawBits() == rhs.getRawBits();
}

bool 	Fixed::operator!=( const Fixed & rhs ) const {

	if (_loud)
    {
		std::cout << "[Fixed] Is-not-equal operator called" << std::endl;
    }
	return getRawBits() != rhs.getRawBits();
}


///			Arithmetic operators

Fixed 	Fixed::operator+( const Fixed & rhs ) const {

	Fixed	answer(*this);

	if (_loud)
    {
		std::cout << "[Fixed] Arithmetic '+' operator called" << std::endl;
    }
	answer.setRawBits(answer.getRawBits() + rhs.getRawBits());
	return answer;
}

Fixed 	Fixed::operator-( const Fixed & rhs ) const {

	Fixed	answer(*this);

	if (_loud)
    {
		std::cout << "[Fixed] Arithmetic '-' operator called" << std::endl;
    }
	answer.setRawBits(answer.getRawBits() - rhs.getRawBits());
	return answer;
}

Fixed 	Fixed::operator*( const Fixed & rhs ) const {

	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed 	Fixed::operator/( const Fixed & rhs ) const {

	return Fixed(this->toFloat() / rhs.toFloat());
}


///			Pre-/Post-Increment / Decrement overloading

Fixed 	Fixed::operator++( void ) {

	if (_loud)
    {
		std::cout << "[Fixed] Arithmetic (pre)'++' operator called" << std::endl;
    }
	this->setRawBits(this->getRawBits() + 1);
	return Fixed(*this);;
}

Fixed 	Fixed::operator++( int ) {

	Fixed	old(*this);

	if (_loud)
    {
		std::cout << "[Fixed] Arithmetic '++'(post) operator called" << std::endl;
    }
	this->setRawBits(this->getRawBits() + 1);
	return old;
}
Fixed 	Fixed::operator--( void ) {

	if (_loud)
    {
		std::cout << "[Fixed] Arithmetic (pre)'--' operator called" << std::endl;
    }
	this->setRawBits(this->getRawBits() - 1);
	return Fixed(*this);;
}

Fixed 	Fixed::operator--( int ) {

	Fixed	old(*this);

	if (_loud)
    {
		std::cout << "[Fixed] Arithmetic '--'(post) operator called" << std::endl;
    }
	this->setRawBits(this->getRawBits() - 1);
	return old;
}


///			Functions / Methods

float	Fixed::toFloat( void ) const {

	int		integer_part = getRawBits() >> _fractional_bits;
	int		float_part = getRawBits() - (integer_part << _fractional_bits);

	return ((float)integer_part + (float)(float_part) / (1 << (_fractional_bits)));
}

int		Fixed::toInt( void ) const {

	return this->_fixed_point >> _fractional_bits;
}

Fixed &	Fixed::min( Fixed & a, Fixed & b ) {

	if (a < b)
	{
		return a;
	}
	return b;
}

const Fixed &	Fixed::min( Fixed const & a, Fixed const & b ) {

	if (a < b)
	{
		return a;
	}
	return b;
}

Fixed &	Fixed::max( Fixed & a, Fixed & b ) {

	if (a > b)
	{
		return a;
	}
	return b;
}

const Fixed &	Fixed::max( Fixed const & a, Fixed const & b ) {

	if (a > b)
	{
		return a;
	}
	return b;
}

///			Private:

std::ostream &	operator<<( std::ostream & o_stream, const Fixed & fix ) {

	return o_stream << fix.toFloat();
}

int	const	Fixed::_fractional_bits = 8;
bool		Fixed::_loud = true;
