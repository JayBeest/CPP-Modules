#include "ShrubberyCreationForm.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target )
: AForm("ShrubberyCreationForm", target, 145, 137) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Specific constructor called" << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
	}
					// TODO hide this one in private?
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & other )
: AForm("ShrubberyCreationForm", other.getTarget(), 145, 137) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
	}
	// TODO
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs ) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
			// TODO
	}
	return *this;
}

///			Functions / Methods

void	ShrubberyCreationForm::executeConcrete( const Bureaucrat & executor ) const {

	// TODO implement write ASCII tree in <tartget>_shrubbery file..
}

///			Private:
