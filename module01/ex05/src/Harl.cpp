#include <iostream>
#include <map>
#include "Harl.hpp"

///			Public:

void	Harl::complain( std::string level ) {

	for (int i = 0; i < 4; i++) {
		if (level == this->_karen_state[i])
			(*this.*this->_funptr[i])();
	}

}

///			Constructor/Destroyer

Harl::Harl(	) {

	_funptr[0] = &Harl::debug;
	_funptr[1] = &Harl::info;
	_funptr[2] = &Harl::warning;
	_funptr[3] = &Harl::error;
	_karen_state[0] = "DEBUG";
	_karen_state[1] = "INFO";
	_karen_state[2] = "WARNING";
	_karen_state[3] = "ERROR";

}

Harl::Harl( const Harl& other) {

	if (this != &other)
	{
		*this = other;
	}
}

Harl::~Harl( ) {

	// TODO

}

Harl &	Harl::operator=( const Harl& rhs ) {

	if (this != &rhs)
	{
	}
	return *this;
}

///			Functions/Methods

///			Private:

void	Harl::debug( void ) {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-";
	std::cout << "ketchup burger. I really do!";
	std::cout << std::endl;

}

void	Harl::info( void ) {

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put ";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;

}

void	Harl::warning( void ) {

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ";
	std::cout << "years whereas you started working here since last month.";
	std::cout << std::endl;

}

void	Harl::error( void ) {

	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;

}
