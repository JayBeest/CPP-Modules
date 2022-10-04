#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		Form::makeSilent();
	}

    try_catch_bureaucrat("Bob", 2);
	std::cout << std::endl;
    try_catch_bureaucrat("Eve", 0);
	std::cout << std::endl;
    try_catch_bureaucrat("Ben", 152);
	std::cout << std::endl;

	Bureaucrat useful("Adam", 1);
	Bureaucrat sloth("Harl", 150);

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
		Form form1("testform 1", 150);
		std::cout << form1;
		sloth.signForm(form1);
		std::cout << form1;
		Form form2("testform 2", 1);
		sloth.signForm(form2);
		std::cout << form2;
	}
	catch(std::exception & e)
	{
		std::cout << "exception: " << e.what() << " caught during construction" << std::endl;
	}


	return 0;
}
