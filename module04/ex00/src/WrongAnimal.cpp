#include "WrongAnimal.hpp"

///			Public:

///			Getters / Setters

std::string		WrongAnimal::getType( ) const {

	return this->type;
}

///			Constructor / Destructor

WrongAnimal::WrongAnimal( const std::string & type ) : type(type) {

	if (WrongAnimal::_loud)
	{
  		std::cout << "[WrongAnimal] Specific constructor called" << std::endl;
	}
}

WrongAnimal::WrongAnimal( ) : type("WrongShapeless"){

	if (WrongAnimal::_loud)
	{
  		std::cout << "[WrongAnimal] Default constructor called" << std::endl;
	}
}

WrongAnimal::WrongAnimal( const WrongAnimal & other ) {

	if (WrongAnimal::_loud)
	{
  		std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
		*this = other;
	}
}

WrongAnimal::~WrongAnimal( ) {

	if (WrongAnimal::_loud)
	{
  		std::cout << "[WrongAnimal] Destructor called" << std::endl;
	}
}

WrongAnimal &	WrongAnimal::operator=( const WrongAnimal & rhs ) {

	if (WrongAnimal::_loud)
	{
  		std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

///			Functions / Methods

void	WrongAnimal::makeSound( void ) const {

	std::cout << "Wharrgarbl!" << std::endl;
}

void	WrongAnimal::makeSilent( void ) {

	WrongAnimal::_loud = false;
}

///			Private:

std::ostream &	operator<<( std::ostream & o_stream, const WrongAnimal & animal ) {

	return o_stream << animal.getType();
}


bool	WrongAnimal::_loud = true;

