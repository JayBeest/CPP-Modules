#include "Ice.hpp"
#include "Character.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Ice::Ice( ) : AMateria("ice"){

	if (AMateria::_loud)
	{
  		std::cout << "[Ice] Default constructor called" << std::endl;
	}
}

Ice::Ice( const Ice & other ) : AMateria(other) {

	if (AMateria::_loud)
	{
  		std::cout << "[Ice] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Ice::~Ice( ) {

	if (AMateria::_loud)
	{
  		std::cout << "[Ice] Destructor called" << std::endl;
	}
}

Ice &	Ice::operator=( const Ice & rhs ) {

	if (AMateria::_loud)
	{
  		std::cout << "[Ice] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		// TODO ?
	}
	return *this;
}

///			Functions / Methods

void	Ice::use( ICharacter & target ) const {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice *	Ice::clone( void ) const {

	std::cout << "cloning " << this->getType() << " .. " << std::endl;
	return new Ice(*this);
}

///			Private:
