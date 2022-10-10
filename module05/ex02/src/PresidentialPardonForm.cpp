#include "PresidentialPardonForm.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

PresidentialPardonForm::PresidentialPardonForm( const std::string & target )
: AForm("PresidentialPardonForm", target, 25, 5) {

	if (AForm::_loud)
	{
  		std::cout << "[PresidentialPardonForm] Specific constructor called" << std::endl;
	}
}

PresidentialPardonForm::PresidentialPardonForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
	}
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & other )
: AForm("PresidentialPardonForm", other.getTarget(), 25, 5) {

	if (AForm::_loud)
	{
  		std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

PresidentialPardonForm::~PresidentialPardonForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
	}
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( const PresidentialPardonForm & rhs ) {

	if (AForm::_loud)
	{
  		std::cout << "[PresidentialPardonForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
	}
	return *this;
}

///			Functions / Methods

void	PresidentialPardonForm::executeConcrete( ) const {


	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

///			Private:

