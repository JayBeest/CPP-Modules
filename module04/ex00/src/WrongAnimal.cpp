#include "WrongAnimal.hpp"

///			Public:

///			Getters / Setters

std::string		WrongAnimal::getType( ) const {

	return this->type;
}

///			Constructor / Destructor

WrongAnimal::WrongAnimal( std::string type ) : type(type) {

	if (WrongAnimal::_loud)
  		std::cout << "[WrongAnimal] Specific constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( ) : type("Shapeless"){

	if (WrongAnimal::_loud)
  		std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & other ) {

	if (this != &other)
	{
	  *this = other;
	}
	if (WrongAnimal::_loud)
  		std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( ) {

	if (WrongAnimal::_loud)
  		std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=( const WrongAnimal & rhs ) {

	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	if (WrongAnimal::_loud)
  		std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
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


bool	WrongAnimal::_loud = true;

