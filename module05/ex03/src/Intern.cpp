#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

Intern::Intern( ) {

	if (Intern::_loud)
	{
  		std::cout << "[Intern] Default constructor called" << std::endl;
	}
}

Intern::Intern( const Intern & other ) {

	if (Intern::_loud)
	{
  		std::cout << "[Intern] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Intern::~Intern( ) {

	if (Intern::_loud)
	{
  		std::cout << "[Intern] Destructor called" << std::endl;
	}
}

Intern &	Intern::operator=( const Intern & rhs ) {

	if (Intern::_loud)
	{
  		std::cout << "[Intern] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
	}
	return *this;
}

///			Functions / Methods

AForm *	Intern::makeForm( const std::string & name, const std::string & target) const {

	const static std::string form_list[DEFAULT * 2] = {
			"shrubbery creation",
			"shrubbery",
			"robotomy request",
			"robotomy",
			"presidential pardon",
			"presidential" };

	int form_type = DEFAULT;
	for (int i = 0; i < (int)(DEFAULT * 2); i++) {
		if (form_list[i] == name)
		{
			form_type = i / 2;
			break;
		}
	}
	switch (form_type)
	{
		case SHRUBBERY:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(target);
		case ROBOTOMY:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(target);
		case PRESIDENTIAL:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cerr << name << " not found, not returning a form.." << std::endl;
			return NULL;
	}
}

void	Intern::makeSilent( void ) {

	Intern::_loud = false;
}

///			Private:


bool	Intern::_loud = true;

