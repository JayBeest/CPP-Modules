#include <iomanip>
#include "Form.hpp"
#include "Bureaucrat.hpp"

///			Public:

///			Getters / Setters

std::string		Form::getName( ) const {

	return this->_name;
}

bool	Form::getSigned( ) const {

	return this->_signed;
}

unsigned int	Form::getRequiredGrade( ) const {

	return this->_required_grade;
}

///			Constructor / Destructor

Form::Form( const std::string & name, const unsigned int & required_grade )
: _name(name), _signed(false), _required_grade(required_grade) {

	if (Form::_loud)
	{
		std::cout << "[Form] Specific constructor called" << std::endl;
	}
	if (required_grade > 150)
	{
		throw Form::GradeTooLowException();
	}
	else if (required_grade < 1)
	{
		throw Form::GradeTooHighException();
	}
}

Form::Form( ) : _name("<default_form>"), _signed(false), _required_grade(150) {

	if (Form::_loud)
	{
		std::cout << "[Form] Default constructor called" << std::endl;
	}
}

Form::Form( const Form & other )
: _name(other.getName()), _signed(false), _required_grade(other.getRequiredGrade()) {

	if (Form::_loud)
	{
		std::cout << "[Form] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Form::~Form( ) {

	if (Form::_loud)
	{
		std::cout << "[Form] Destructor called" << std::endl;
	}
}

Form &	Form::operator=( const Form & rhs ) {

	if (Form::_loud)
	{
		std::cout << "[Form] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

///			Functions / Methods

void	Form::beSigned( const Bureaucrat & bureaucrat ) {

	if (this->getRequiredGrade() >= bureaucrat.getGrade())
	{
		this->_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

void	Form::makeSilent( void ) {

	Form::_loud = false;
}

///			Private:

std::ostream &	operator<<( std::ostream & o_stream, const Form & form ) {

	o_stream << std::setw(16) << "form name: " << form.getName() << std::endl
	<< std::setw(16) << "required grade: " << form.getRequiredGrade() << std::endl
	<< std::setw(16) << "is signed: " << form.getSigned() << std::endl;
	return o_stream;
}

bool	Form::_loud = true;
