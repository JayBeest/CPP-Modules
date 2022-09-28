#include "Cure.hpp"
#include "Character.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Cure::Cure( ) : AMateria("cure"){

	if (AMateria::_loud)
  		std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure( const Cure & other ) {

	if (this != &other)
	{
	  *this = other;
	}
	if (AMateria::_loud)
  		std::cout << "[Cure] Copy constructor called" << std::endl;
}

Cure::~Cure( ) {

	// TODO
	if (AMateria::_loud)
  		std::cout << "[Cure] Destructor called" << std::endl;
}

Cure &	Cure::operator=( const Cure & rhs ) {

	if (this != &rhs)
	{
	}
	if (AMateria::_loud)
  		std::cout << "[Cure] Copy assignment operator called" << std::endl;
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
