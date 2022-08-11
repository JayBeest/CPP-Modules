#include <iostream>
#include "Cat.hpp"

///			Public:

///			Getters / Setters

Brain &	Cat::accessBrain( void ) const {

	return *this->_brain;
}

///			Constructor / Destructor

Cat::Cat( std::string type ) : Animal(type) {

	this->_brain = new Brain(type + "-thought");
	if (Animal::_loud)
  		std::cout << "[Cat] Specific constructor called" << std::endl;
}

Cat::Cat( ) : Animal("Cat") {

	this->_brain = new Brain("Cat-thought");
	if (Animal::_loud)
  		std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat( const Cat& other) {

	if (this != &other)
	{
		delete this->_brain;
	  *this = other;
	}
	if (Animal::_loud)
  		std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat::~Cat( ) {

	if (Animal::_loud)
  		std::cout << "[Cat] Destructor called" << std::endl;
	delete _brain;
}

Cat &	Cat::operator=( const Cat& rhs ) {

	if (this != &rhs)
	{
//		delete this->_brain;
		this->type = rhs.getType();
		this->_brain = new Brain(rhs.accessBrain());
	}
	if (Animal::_loud)
  		std::cout << "[Cat] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	Cat::makeSound( void ) const {

	std::cout << "Miauw!" << std::endl;
}

void	Cat::makeSilent( void ) {

	Animal::_loud = false;
}

///			Private:

