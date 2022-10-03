#include "Bureaucrat.hpp"

///			Public:

///			Getters / Setters

std::string	Bureaucrat::getName( void ) const {

	return this->_name;
}

unsigned int    Bureaucrat::getGrade( void ) const {

	return this->_grade;
}

///			Constructor / Destructor

Bureaucrat::Bureaucrat( const std::string & name, unsigned int grade ) : _name(name) {

	if (Bureaucrat::_loud)
	{
  		std::cout << "[Bureaucrat] Specific constructor called" << std::endl;
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else
	{
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat( ) {

	if (Bureaucrat::_loud)
	{
  		std::cout << "[Bureaucrat] Default constructor called" << std::endl;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & other ) {

	if (Bureaucrat::_loud)
	{
  		std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Bureaucrat::~Bureaucrat( ) {

	if (Bureaucrat::_loud)
	{
  		std::cout << "[Bureaucrat] Destructor called" << std::endl;
	}
}

Bureaucrat &	Bureaucrat::operator=( const Bureaucrat & rhs ) {

	if (Bureaucrat::_loud)
	{
  		std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

void    Bureaucrat::incrGrade( void ) {

    if (this->_grade > 1)
	{
        this->_grade--;
	}
    else
	{
        throw Bureaucrat::GradeTooHighException();
	}
}

void    Bureaucrat::decrGrade( void ) {

    if (this->_grade < 150)
	{
        this->_grade++;
	}
    else
	{
        throw Bureaucrat::GradeTooLowException();
	}
}

///			Functions / Methods

void	Bureaucrat::makeSilent( void ) {

	Bureaucrat::_loud = false;
}

///			Private:

bool	Bureaucrat::_loud = true;

std::ostream &	operator<<( std::ostream & o_stream, const Bureaucrat & bureaucrat ) {

    o_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return o_stream;
}
