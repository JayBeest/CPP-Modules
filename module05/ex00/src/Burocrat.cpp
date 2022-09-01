#include <iostream>
#include "Burocrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

///			Public:

///			Getters / Setters

std::string	Burocrat::getName( void ) const {

	return this->_name;
}

unsigned int    Burocrat::getGrade( void ) const {

	return this->_grade;
}

///			Constructor / Destructor

Burocrat::Burocrat( const std::string & name, unsigned int grade ) : _name(name) {

	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Specific constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Burocrat::Burocrat( ) {

	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Default constructor called" << std::endl;
}

Burocrat::Burocrat( const Burocrat & other ) {

	if (this != &other)
	{
	  *this = other;
	}
	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Copy constructor called" << std::endl;
}

Burocrat::~Burocrat( ) {

	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Destructor called" << std::endl;
}

Burocrat &	Burocrat::operator=( const Burocrat & rhs ) {

	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	if (Burocrat::_loud)
  		std::cout << "[Burocrat] Copy assignment operator called" << std::endl;
	return *this;
}

void    Burocrat::incrGrade( void ) {

    if (this->_grade > 1)
        this->_grade--;
}

void    Burocrat::decrGrade( void ) {

    if (this->_grade < 150)
        this->_grade++;
}

///			Functions / Methods

void	Burocrat::makeSilent( void ) {

	Burocrat::_loud = false;
}

///			Private:

bool	Burocrat::_loud = true;

