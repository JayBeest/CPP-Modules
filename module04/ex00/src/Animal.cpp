#include "Animal.hpp"

///			Public:

///			Getters / Setters

const std::string &	Animal::getType( ) const {

	return this->type;
}

///			Constructor / Destructor

Animal::Animal( const std::string & type ) : type(type) {

	if (Animal::_loud)
	{
  		std::cout << "[Animal] Specific constructor called" << std::endl;
	}
}

Animal::Animal( ) : type("Shapeless"){

	if (Animal::_loud)
	{
  		std::cout << "[Animal] Default constructor called" << std::endl;
	}
}

Animal::Animal( const Animal & other ) {

	if (Animal::_loud)
	{
  		std::cout << "[Animal] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Animal::~Animal( ) {

	if (Animal::_loud)
	{
  		std::cout << "[Animal] Destructor called" << std::endl;
	}
}

Animal &	Animal::operator=( const Animal & rhs ) {

	if (Animal::_loud)
	{
  		std::cout << "[Animal] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

///			Functions / Methods

void	Animal::makeSound( void ) const {

	std::cout << "Wharrgarbl!" << std::endl;
}

void	Animal::makeSilent( void ) {

	Animal::_loud = false;
}

///			Private:


bool	Animal::_loud = true;

std::ostream &	operator<<( std::ostream & o_stream, const Animal & animal ) {

	return o_stream << animal.getType();
}
