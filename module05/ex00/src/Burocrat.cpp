#include <iostream>
#include "Burocrat.hpp"

///			Public:

///			Getters / Setters

std::string	Burocrat::getName( ) const {

	return this->_name;
}

int		Burocrat::getGrade( ) const {

	return this->_grade;
}

///			Constructor / Destructor

Burocrat::Burocrat( const std::string & name, unsigned int grade ) : _name(name) {

	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Specific constructor called" << std::endl;
	if (grade > 150)
		throw Burocrat::GradeTooLowException("error");
	else if (grade < 1)
		throw Burocrat::GradeTooHighException("error");
	else
		this->_grade = grade;
}

Burocrat::Burocrat( ) {

										// TODO not counting default constructor
	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Default constructor called" << std::endl;
}

Burocrat::Burocrat( const Burocrat& other) {

	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Copy constructor called" << std::endl;
}

Burocrat::~Burocrat( ) {

	// TODO
	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Destructor called" << std::endl;
}

Burocrat &	Burocrat::operator=( const Burocrat& rhs ) {

	if (this != &rhs)
	{
		this->_vars = rhs.getVars();	// TODO
	}
	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	Burocrat::doStuff( ) const {

	// TODO

}

void	Burocrat::makeSilent( void ) {

	Burocrat::_loud = false;
}

///			Private:



int	Burocrat::_nb_Burocrat_created = 0;

bool	Burocrat::_loud = true;

