#include <iostream>
#include "Brain.hpp"

///			Public:

///			Getters / Setters


std::string		Brain::getIdea( unsigned int index ) const {

	if (index >= MAX_IDEAS)
		return "index out of range!";
	return this->ideas[index];
}

///			Constructor / Destructor

Brain::Brain( const std::string & first_idea ) : ideas() {

	this->ideas[0] = first_idea;
	if (Brain::_loud)
  		std::cout << "[Brain] Specific constructor called" << std::endl;
}

Brain::Brain( ) : ideas() {

	if (Brain::_loud)
  		std::cout << "[Brain] Default constructor called" << std::endl;
}

Brain::Brain( const Brain& other) {

	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
	if (Brain::_loud)
  		std::cout << "[Brain] Copy constructor called" << std::endl;
}

Brain::~Brain( ) {

	// TODO
	if (Brain::_loud)
  		std::cout << "[Brain] Destructor called" << std::endl;
}

Brain &	Brain::operator=( const Brain & rhs ) {

	if (this != &rhs)
	{
		this->ideas[0] = rhs.getIdea(0);	// TODO + tests!!
	}
	if (Brain::_loud)
  		std::cout << "[Brain] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	Brain::makeSilent( void ) {

	Brain::_loud = false;
}

///			Private:

bool	Brain::_loud = true;

