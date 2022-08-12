#include <iostream>
#include "Ice.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Ice::Ice( ) : AMateria("ice"){

	if (AMateria::_loud)
  		std::cout << "[Ice] Default constructor called" << std::endl;
}

Ice::Ice( const Ice& other) {

	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
	if (AMateria::_loud)
  		std::cout << "[Ice] Copy constructor called" << std::endl;
}

Ice::~Ice( ) {

	// TODO
	if (AMateria::_loud)
  		std::cout << "[Ice] Destructor called" << std::endl;
}

Ice &	Ice::operator=( const Ice& rhs ) {

	if (this != &rhs)
	{
	}
	if (AMateria::_loud)
  		std::cout << "[Ice] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

AMateria *	Ice::clone( void ) const {

	std::cout << "cloning... andr returning nullptr...:P" << std::endl;
	// TODO

	return nullptr;
}

///			Private:
