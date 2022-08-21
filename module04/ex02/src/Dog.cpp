#include <iostream>
#include "Dog.hpp"

///			Public:

///			Getters / Setters

Brain &	Dog::accessBrain( void ) const {

	return *this->_brain;
}

///			Constructor / Destructor

Dog::Dog( std::string type ) : Animal(type), _brain(new Brain(type + "-thought")) {

	if (Animal::_loud)
  		std::cout << "[Dog] Specific constructor called" << std::endl;
}

Dog::Dog( ) : Animal("Dog"), _brain(new Brain("Dog-thought")) {

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
	delete _brain;
}

Dog &	Dog::operator=( const Dog& rhs ) {

	if (this != &rhs)
	{
		delete this->_brain;
		this->type = rhs.getType();
		this->_brain = new Brain(rhs.accessBrain());
	}
	if (Animal::_loud)
  		std::cout << "[Dog] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	Dog::makeSound( void ) const {

	std::cout << "Miauw!" << std::endl;
}

void	Dog::makeSilent( void ) {

	Animal::_loud = false;
}

///			Private:
