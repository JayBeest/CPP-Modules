#include <iostream>
#include "WrongCat.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

WrongCat::WrongCat( std::string type ) : WrongAnimal(type) {

	if (WrongAnimal::_loud)
  		std::cout << "[WrongCat] Specific constructor called" << std::endl;
}

WrongCat::WrongCat( ) : WrongAnimal("WrongCat") {

	if (WrongAnimal::_loud)
  		std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other) {

	if (this != &other)
	{
	  *this = other;
	}
	if (WrongAnimal::_loud)
  		std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat::~WrongCat( ) {

	// TODO
	if (WrongAnimal::_loud)
  		std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat &	WrongCat::operator=( const WrongCat& rhs ) {

	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	if (WrongAnimal::_loud)
  		std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	WrongCat::makeSound( void ) const {

	std::cout << "Miauw!" << std::endl;
}

void	WrongCat::makeSilent( void ) {

	WrongAnimal::_loud = false;
}

///			Private:

