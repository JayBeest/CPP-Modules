//#include <ctime>
//#include <cstdlib>
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
	}
}

RobotomyRequestForm::~RobotomyRequestForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
	}
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( const RobotomyRequestForm & rhs ) {

	if (AForm::_loud)
	{
  		std::cout << "[RobotomyRequestForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
	}
	return *this;
}

///			Functions / Methods

void	RobotomyRequestForm::executeConcrete( ) const {

	std::cout << "*** drilling noises ***" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
	{
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "the robotomy failed.." << std::endl;
	}
}

///			Private:

