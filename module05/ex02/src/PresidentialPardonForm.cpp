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
					// TODO hide this one in private?
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
	  // TODO
	}
}

PresidentialPardonForm::~PresidentialPardonForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
	}
	// TODO
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( const PresidentialPardonForm & rhs ) {

	if (AForm::_loud)
	{
  		std::cout << "[PresidentialPardonForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
			// TODO
	}
	return *this;
}

///			Functions / Methods

void	PresidentialPardonForm::executeConcrete( const Bureaucrat & executor ) const {

	// TODO implement write ASCII tree in <tartget>_shrubbery file..
}

///			Private:

