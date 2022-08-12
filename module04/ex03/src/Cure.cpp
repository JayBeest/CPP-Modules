#include <iostream>
#include "Cure.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Cure::Cure( ) : AMateria("cure"){

	if (AMateria::_loud)
  		std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure( const Cure& other) {

	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
	if (AMateria::_loud)
  		std::cout << "[Cure] Copy constructor called" << std::endl;
}

Cure::~Cure( ) {

	// TODO
	if (AMateria::_loud)
  		std::cout << "[Cure] Destructor called" << std::endl;
}

Cure &	Cure::operator=( const Cure& rhs ) {

	if (this != &rhs)
	{
	}
	if (AMateria::_loud)
  		std::cout << "[Cure] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

AMateria *	Cure::clone( void ) const {

	std::cout << "cloning... andr returning nullptr...:P" << std::endl;
	// TODO

	return nullptr;
}

///			Private:
