#include <iostream>
#include "Animal.hpp"

///			Public:

///			Getters / Setters

std::string		Animal::getType( ) const {

	return this->type;
}

///			Constructor / Destructor

Animal::Animal( std::string type ) : type(type) {

	if (Animal::_loud)
  		std::cout << "[Animal] Specific constructor called" << std::endl;
}

Animal::Animal( ) : type("Shapeless"){

	if (Animal::_loud)
  		std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal( const Animal& other) {

	if (this != &other)
	{
	  *this = other;
	}
	if (Animal::_loud)
  		std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal::~Animal( ) {

	if (Animal::_loud)
  		std::cout << "[Animal] Destructor called" << std::endl;
}

Animal &	Animal::operator=( const Animal& rhs ) {

	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	if (Animal::_loud)
  		std::cout << "[Animal] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	Animal::makeSilent( void ) {

	Animal::_loud = false;
}

///			Private:

bool	Animal::_loud = true;

std::ostream & operator<<( std::ostream & o_stream, const Animal & animal ) {

	return o_stream << animal.getType();
}
