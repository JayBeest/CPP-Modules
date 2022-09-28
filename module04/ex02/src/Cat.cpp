#include "Cat.hpp"

///			Public:

///			Getters / Setters

Brain &	Cat::accessBrain( void ) const {

	return *this->_brain;
}

///			Constructor / Destructor

Cat::Cat( std::string type ) : AAnimal(type), _brain(new Brain(type + "-thought")) {

	if (AAnimal::_loud)
	{
  		std::cout << "[Cat] Specific constructor called" << std::endl;
	}
}

Cat::Cat( )
	: AAnimal("Cat"), _brain(new Brain("Cat-thought")) {

	if (AAnimal::_loud)
	{
  		std::cout << "[Cat] Default constructor called" << std::endl;
	}
}

Cat::Cat( const Cat & other ) {

	if (AAnimal::_loud)
	{
  		std::cout << "[Cat] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
		*this = other;
	}
}

Cat::~Cat( ) {

	if (AAnimal::_loud)
	{
  		std::cout << "[Cat] Destructor called" << std::endl;
	}
	delete _brain;
}

Cat &	Cat::operator=( const Cat & rhs ) {

	if (AAnimal::_loud)
	{
  		std::cout << "[Cat] Copy assignment operator called" << std::endl;
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

void	Cat::makeSound( void ) const {

	std::cout << "Miauw!" << std::endl;
}

///			Private:
