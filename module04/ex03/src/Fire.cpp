#include "Fire.hpp"
#include "Character.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Fire::Fire( ) : AMateria("fire"){

	if (AMateria::_loud)
	{
  		std::cout << "[Fire] Default constructor called" << std::endl;
	}
}

Fire::Fire( const Fire & other ) : AMateria(other) {

	if (AMateria::_loud)
	{
  		std::cout << "[Fire] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Fire::~Fire( ) {

	if (AMateria::_loud)
	{
  		std::cout << "[Fire] Destructor called" << std::endl;
	}
}

Fire &	Fire::operator=( const Fire & rhs ) {

	if (AMateria::_loud)
	{
  		std::cout << "[Fire] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		// TODO ?
	}
	return *this;
}

///			Functions / Methods

void	Fire::use( ICharacter & target ) const {

	std::cout << "* lobs a fireball at " << target.getName() << " *" << std::endl;
}

Fire *	Fire::clone( void ) const {

	std::cout << "cloning " << this->getType() << " .. " << std::endl;
	return new Fire(*this);
}

///			Private:
