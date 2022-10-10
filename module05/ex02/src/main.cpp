#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void try_incr_bureaucrat(Bureaucrat & bureau)
{
	try {
		std::cout << "Trying to increase grade of " << bureau << std::endl;
		bureau.incrGrade();
	}
	catch (std::exception & e) {
		std::cerr << "caught: " << e.what() << "!" << std::endl;
	}
}

void try_decr_bureaucrat(Bureaucrat & bureau)
{
	try {
		std::cout << "Trying to decrease grade of " << bureau << std::endl;
		bureau.decrGrade();
	}
	catch (std::exception & e) {
		std::cerr << "caught: " << e.what() << "!" << std::endl;
	}
}

void    try_catch_bureaucrat(const std::string & name, unsigned int grade)
{
    try {
        Bureaucrat test(name, grade);
        std::cout << test << ": End of try-block" << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "caught: " << e.what() << "!" << std::endl;
    }
}

int main ( int argc, char **argv ) {

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << "Silencing [Bureaucrat].. to silence [Form] as well use -s2" << std::endl << std::endl;
		Bureaucrat::makeSilent();
	}
	else if (argc == 2 && std::string(argv[1]) == "-s2")
	{
		std::cout << "Silencing [Bureaucrat].." << std::endl;
		Bureaucrat::makeSilent();
		std::cout << "Silencing [Form].." << std::endl << std::endl;
		AForm::makeSilent();
	}

    try_catch_bureaucrat("Bob", 2);
	std::cout << std::endl;
    try_catch_bureaucrat("Eve", 0);
	std::cout << std::endl;
    try_catch_bureaucrat("Ben", 152);
	std::cout << std::endl;

	Bureaucrat useful("Adam", 1);
	Bureaucrat sloth("Harl", 140);

	try_incr_bureaucrat(useful);
	try_decr_bureaucrat(useful);
	std::cout << useful << std::endl;
	std::cout << std::endl;
	try_decr_bureaucrat(sloth);
	try_incr_bureaucrat(sloth);
	std::cout << sloth << std::endl;
	std::cout << std::endl;

	try
	{
		ShrubberyCreationForm form1("bullseye");
		std::cout << form1;
		useful.signForm(form1);
		std::cout << form1;
		ShrubberyCreationForm form2("Osama");
		std::cout << form2;
		RobotomyRequestForm form3("blok beton");
		std::cout << form3;
		useful.signForm(form3);
		PresidentialPardonForm form4("Bannon");
		std::cout << form4;
		useful.signForm(form4);
//		form3.execute(useful);
//		form3.execute(sloth);
		std::cout << std::endl;
		sloth.executeForm(form1);
		sloth.executeForm(form2);
		sloth.executeForm(form3);
		sloth.executeForm(form4);
		std::cout << std::endl;
		useful.executeForm(form1);
		useful.executeForm(form2);
		useful.executeForm(form3);
		useful.executeForm(form4);
	}
	catch(std::exception & e)
	{
		std::cout << "exception: " << e.what() << " caught during construction" << std::endl;
	}
	std::cout << "---->  Just before end of main" << std::endl;

	return 0;
}
