#include "Cat.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Cat::Cat( const std::string & type ) : Animal(type) {

	if (Animal::_loud)
	{
  		std::cout << "[Cat] Specific constructor called" << std::endl;
	}
}

Cat::Cat( ) : Animal("Cat") {

	if (Animal::_loud)
	{
  		std::cout << "[Cat] Default constructor called" << std::endl;
	}
}

Cat::Cat( const Cat & other ) {

	if (Animal::_loud)
	{
  		std::cout << "[Cat] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Cat::~Cat( ) {

	if (Animal::_loud)
	{
  		std::cout << "[Cat] Destructor called" << std::endl;
	}
}

Cat &	Cat::operator=( const Cat & rhs ) {

	if (Animal::_loud)
	{
  		std::cout << "[Cat] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
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

