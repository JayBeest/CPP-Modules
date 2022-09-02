#include <iostream>
#include "Bureaucrat.hpp"

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
    try_catch_bureaucrat("Eve", 0);
    try_catch_bureaucrat("Ben", 152);

	return 0;
}
