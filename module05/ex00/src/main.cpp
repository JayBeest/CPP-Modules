#include <iostream>
#include "Bureaucrat.hpp"

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

int main ( void ) {

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
	return 0;
}
