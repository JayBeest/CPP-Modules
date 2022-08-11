#include <iostream>
#include "Dog.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Dog::Dog( std::string type ) : Animal(type) {

	if (Animal::_loud)
  		std::cout << "[Dog] Specific constructor called" << std::endl;
}

Dog::Dog( ) : Animal("Dog") {

	if (Animal::_loud)
  		std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog( const Dog& other) {

	if (this != &other)
	{
	  *this = other;
	}
	if (Animal::_loud)
  		std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog::~Dog( ) {

	if (Animal::_loud)
  		std::cout << "[Dog] Destructor called" << std::endl;
}

Dog &	Dog::operator=( const Dog& rhs ) {

	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	if (Animal::_loud)
  		std::cout << "[Dog] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	Dog::makeSound( void ) const {

	std::cout << "Waf!" << std::endl;
}

void	Dog::makeSilent( void ) {

	Animal::_loud = false;
}

///			Private:

std::ostream & operator<<( std::ostream & o_stream, const Animal & animal ) {

	return o_stream << animal.getType();
}

