#include <iostream>
#include "Burocrat.hpp"

void    try_catch_burocrat(const std::string & name, unsigned int grade)
{
    try {
        Burocrat test(name, grade);
    }
    catch (std::exception & e) {
        std::cout << "caught: " << e.what() << "!" << std::endl;
    }
}

int main ( void ) {

    try_catch_burocrat("bob", 2);
    try_catch_burocrat("eve", 0);
    try_catch_burocrat("ben", 152);
//    try {
//        Burocrat test("eve", 0);
//    }
//    catch (std::exception & e) {
//        std::cout << "caught: " << e.what() << "!" << std::endl;
//    }

	return 0;
}
