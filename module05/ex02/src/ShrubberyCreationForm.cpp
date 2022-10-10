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
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
	}
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs ) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
	}
	return *this;
}

///			Functions / Methods

void	ShrubberyCreationForm::executeConcrete( ) const {

	std::cout << "Implement: Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it..." << std::endl;
}

///			Private:
