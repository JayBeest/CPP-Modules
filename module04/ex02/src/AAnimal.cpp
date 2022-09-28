#include "AAnimal.hpp"

///			Public:

///			Getters / Setters

std::string		AAnimal::getType( ) const {

	return this->type;
}

///			Constructor / Destructor

AAnimal::AAnimal( std::string type ) : type(type) {

	if (AAnimal::_loud)
	{
  		std::cout << "[AAnimal] Specific constructor called" << std::endl;
	}
}

AAnimal::AAnimal( ) : type("Shapeless"){

	if (AAnimal::_loud)
	{
  		std::cout << "[AAnimal] Default constructor called" << std::endl;
	}
}

AAnimal::AAnimal( const AAnimal & other) {

	if (AAnimal::_loud)
	{
  		std::cout << "[AAnimal] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

AAnimal::~AAnimal( ) {

	if (AAnimal::_loud)
	{
  		std::cout << "[AAnimal] Destructor called" << std::endl;
	}
}

AAnimal &	AAnimal::operator=( const AAnimal & rhs ) {

	if (AAnimal::_loud)
	{
  		std::cout << "[AAnimal] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

///			Functions / Methods

void	AAnimal::makeSilent( void ) {

	AAnimal::_loud = false;
}

///			Private:

bool	AAnimal::_loud = true;

std::ostream &	operator<<( std::ostream & o_stream, const AAnimal & animal ) {

	return o_stream << animal.getType();
}
