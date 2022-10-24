#include "Cure.hpp"
#include "Character.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Cure::Cure( ) : AMateria("cure"){

	if (AMateria::_loud)
	{
  		std::cout << "[Cure] Default constructor called" << std::endl;
	}
}

Cure::Cure( const Cure & other ) : AMateria(other) {

	if (AMateria::_loud)
	{
  		std::cout << "[Cure] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Cure::~Cure( ) {

	if (AMateria::_loud)
	{
  		std::cout << "[Cure] Destructor called" << std::endl;
	}
}

Cure &	Cure::operator=( const Cure & rhs ) {

	if (AMateria::_loud)
	{
  		std::cout << "[Cure] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		//TODO ?
	}
	return *this;
}

///			Functions / Methods

void	Cure::use( ICharacter & target ) const {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure *	Cure::clone( void ) const {

	std::cout << "cloning " << this->getType() << " .. " << std::endl;

	return new Cure(*this);
}

///			Private:
