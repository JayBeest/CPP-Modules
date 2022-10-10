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

	enum e_form {
		SHRUBBERY,
		ROBOTOMY,
		PRESIDENTIAL,
		DEFAULT
	};

	static std::string form_list[DEFAULT] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"};

	int form_type = DEFAULT;
	for (int i = 0; i < (int) DEFAULT; i++) {
		if (form_list[i] == name) {
			form_type = i;
			std::cout << "Intern creates " << name << std::endl;
			break;
		}
	}
	switch (form_type)
	{
		case SHRUBBERY:
			return new ShrubberyCreationForm(target);
		case ROBOTOMY:
			return new RobotomyRequestForm(target);
		case PRESIDENTIAL:
			return new PresidentialPardonForm(target);
		case DEFAULT:
			std::cout << name << " not found, not returning a form..";
			return NULL;
	}
}

void	Intern::makeSilent( void ) {

	Intern::_loud = false;
}

///			Private:


bool	Intern::_loud = true;

