#include "ShrubberyCreationForm.hpp"

///			Public:

///			Getters / Setters

int		ShrubberyCreationForm::getId( ) const {

	return this->_id;
}

///			Constructor / Destructor

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target ) : Form("ShrubberyForm", 145) {

	if (Form::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Specific constructor called" << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm( ) {

	if (Form::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
	}
					// TODO not counting default constructor
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & other ) {

	if (Form::_loud)
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

	if (Form::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
	}
	// TODO
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs ) {

	if (Form::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		this->_vars = rhs.getVars();
			// TODO
	}
	return *this;
}

///			Functions / Methods

void	ShrubberyCreationForm::doStuff( ) const {

	// TODO

}

///			Private:



int	ShrubberyCreationForm::_nb_ShrubberyCreationForm_created = 0;

bool	Form::_loud = true;

