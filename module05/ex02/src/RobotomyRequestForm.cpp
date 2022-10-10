#include "RobotomyRequestForm.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

RobotomyRequestForm::RobotomyRequestForm( const std::string & target )
: AForm("RobotomyRequestForm", target, 72, 45) {

	if (AForm::_loud)
	{
  		std::cout << "[RobotomyRequestForm] Specific constructor called" << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
	}
					// TODO hide this one in private?
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & other )
: AForm("RobotomyRequestForm", other.getTarget(), 72, 45) {

	if (AForm::_loud)
	{
  		std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
}

RobotomyRequestForm::~RobotomyRequestForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
	}
	// TODO
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( const RobotomyRequestForm & rhs ) {

	if (AForm::_loud)
	{
  		std::cout << "[RobotomyRequestForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
			// TODO
	}
	return *this;
}

///			Functions / Methods

void	RobotomyRequestForm::executeConcrete( const Bureaucrat & executor ) const {

	// TODO implement write ASCII tree in <tartget>_shrubbery file..
}

///			Private:

