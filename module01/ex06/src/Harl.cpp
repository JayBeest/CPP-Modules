#include <iostream>
#include <map>
#include "Harl.hpp"

///			Public:

void	Harl::complain( std::string level ) {

	t_pain_lvl	hurt;

	for (int i = 0; i < 4; i++) {
		if (level == this->_karen_state[i])
		{
			hurt = (t_pain_lvl)i;
			break;
		}
		if (i == 3)
			hurt = OBNOXIOUS;
	}
	switch (hurt){
		case OBNOXIOUS:
			(this->*this->_funptr[OBNOXIOUS])();
			break;
		case DEBUG:
			(*this.*this->_funptr[DEBUG])();
		case INFO:
			(*this.*this->_funptr[INFO])();
		case WARNING:
			(*this.*this->_funptr[WARNING])();
		case ERROR:
			(this->*this->_funptr[ERROR])();
	}

}

///			Constructor/Destroyer

Harl::Harl(	) {

	_funptr[0] = &Harl::debug;
	_funptr[1] = &Harl::info;
	_funptr[2] = &Harl::warning;
	_funptr[3] = &Harl::error;
	_funptr[4] = &Harl::obnox;
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

	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-";
	std::cout << "ketchup burger. I really do!";
	std::cout << std::endl;

}

void	Harl::info( void ) {

	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put ";
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;

}

void	Harl::warning( void ) {

	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ";
	std::cout << "years whereas you started working here since last month.";
	std::cout << std::endl;

}

void	Harl::error( void ) {

	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;

}

void	Harl::obnox( void ) {

	std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << std::endl;

}