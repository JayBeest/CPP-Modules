#include <iomanip>
#include "Form.hpp"
#include "Bureaucrat.hpp"

///			Public:

///			Getters / Setters

std::string		AForm::getName( ) const {

	return this->_name;
}

bool	AForm::getSigned( ) const {

	return this->_signed;
}

unsigned int	AForm::getRequiredGrade( ) const {

	return this->_required_grade;
}

unsigned int	AForm::getExecGrade( ) const {

	return this->_exec_grade;
}

std::string		AForm::getTarget( ) const {

	return this->_target;
}

///			Constructor / Destructor

AForm::AForm( const std::string & name, const std::string & target, \
	const unsigned int & req_grade, const unsigned int & exec_grade )
: _name(name), _target(target), _required_grade(req_grade), _exec_grade(exec_grade), _signed(false) {

	if (AForm::_loud)
	{
		std::cout << "[Form] Specific constructor called" << std::endl;
	}
	if (req_grade > 150)
	{
		throw AForm::GradeTooLowException();
	}
	else if (req_grade < 1)
	{
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm( )
: _name("<default_form>"), _target("<default_target>"), _required_grade(1), \
	_exec_grade(1), _signed(false) {

	if (AForm::_loud)
	{
		std::cout << "[Form] Default constructor called" << std::endl;
	}
}

AForm::AForm( const AForm & other )
: _name(other.getName()), _target(other.getTarget()), _required_grade(other.getRequiredGrade()),
_exec_grade(other.getExecGrade()), _signed(false) {

	if (AForm::_loud)
	{
		std::cout << "[Form] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

AForm::~AForm( ) {

	if (AForm::_loud)
	{
		std::cout << "[Form] Destructor called" << std::endl;
	}
}

AForm &	AForm::operator=( const AForm & rhs ) {

	if (AForm::_loud)
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

void	AForm::execute( const Bureaucrat & executor ) const {

	if (!this->getSigned())
	{
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}
	this->executeConcrete();
}

void	AForm::beSigned( const Bureaucrat & bureaucrat ) {

	if (this->getRequiredGrade() >= bureaucrat.getGrade())
	{
		this->_signed = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

void	AForm::makeSilent( void ) {

	AForm::_loud = false;
}

///			Private:

std::ostream &	operator<<( std::ostream & o_stream, const AForm & form ) {

	o_stream << std::setw(16) << "form name: " << form.getName() << std::endl
	<< std::setw(16) << "required grade: " << form.getRequiredGrade() << std::endl
	<< std::setw(16) << "is signed: " << form.getSigned() << std::endl;
	return o_stream;
}

bool	AForm::_loud = true;
