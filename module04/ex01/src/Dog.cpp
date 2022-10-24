#include "Dog.hpp"

///			Public:

///			Getters / Setters

Brain &	Dog::accessBrain( void ) const {

	return *this->_brain;
}

///			Constructor / Destructor

Dog::Dog( const std::string & type ) : Animal(type) {

	if (Animal::_loud)
	{
  		std::cout << "[Dog] Specific constructor called" << std::endl;
	}
	this->_brain = new Brain(type + "-thought");
}

Dog::Dog( ) : Animal("Dog") {

	if (Animal::_loud)
	{
  		std::cout << "[Dog] Default constructor called" << std::endl;
	}
	this->_brain = new Brain("Dog-thought");
}

Dog::Dog( const Dog & other ) : Animal(other) {

	if (Animal::_loud)
	{
  		std::cout << "[Dog] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
		*this = other;
	}
}

Dog::~Dog( ) {

	if (Animal::_loud)
	{
  		std::cout << "[Dog] Destructor called" << std::endl;
	}
	delete _brain;
}

Dog &	Dog::operator=( const Dog & rhs ) {

	if (Animal::_loud)
	{
  		std::cout << "[Dog] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		delete this->_brain;
		this->type = rhs.getType();
		this->_brain = new Brain(rhs.accessBrain());
	}
	return *this;
}

///			Functions / Methods

void	Dog::makeSound( void ) const {

	std::cout << "Miauw!" << std::endl;
}

///			Private:
