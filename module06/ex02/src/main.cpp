#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void) {

	int	rando = std::rand() % 3;
	if (rando == 0)
	{
		std::cout << "created an A!" << std::endl;
		return new A;
	}
	else if (rando == 1)
	{
		std::cout << "created a B!" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "created a C!" << std::endl;
		return new C;
	}
}

void	identify(Base * p) {

	std::cout << "identified (as a pointer) - ";
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "'A' class found!" << std::endl;
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "'B' class found!" << std::endl;
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "'C' class found!" << std::endl;
	}
	else
	{
		std::cerr << "unknown class?!?" << std::endl;
	}
}

void	identify(Base & p) {

	std::cout << "identified (as a reference) - ";
	try {
		A & ref = dynamic_cast<A &>(p);
		std::cout << "'A' class found!" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception & e) {}
	try {
		B & ref = dynamic_cast<B &>(p);
		std::cout << "'B' class found!" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception & e) {}
	try {
		C & ref = dynamic_cast<C &>(p);
		std::cout << "'C' class found!" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception & e) {}
}

//void	identify(Base & p) {
//
//
//}

int main ( ){

	std::srand(std::time(NULL));

	for (int i = 0; i < 42; i++)
	{
		Base * ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return 0;
}
