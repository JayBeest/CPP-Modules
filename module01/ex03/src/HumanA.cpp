#include "HumanA.hpp"

///			Public:

bool        HumanA::verbose = false;

///			Getters/Setters

const std::string & HumanA::getName( void ) const {

    return this->_name;
}

///			Constructor/Destroyer

HumanA::HumanA( std::string const & name, Weapon & weapon )
: _name(name), _weapon(weapon) {

	HumanA::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;

}

HumanA::HumanA(	)
: _name("<no_name>"), _weapon(*HumanA::_default_weapon){

	HumanA::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanA's alive (default): " << HumanA::_nb_humanAs_alive << std::endl;
}

HumanA::~HumanA( ) {

	if (HumanA::_nb_humanAs_alive == 1)
	{
		if (verbose)
			std::cout << "deleting default weapon.." << std::endl;
		delete HumanA::_default_weapon;
	}
	// TODO
	HumanA::_nb_humanAs_alive--;
	if (verbose)
		std::cout << "one less, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
}

HumanA::HumanA( HumanA const & other )
: _name(other._name), _weapon(*HumanA::_default_weapon) {

	if (this != &other)
	{
		HumanA::_nb_humanAs_alive++;
		if (verbose)
			std::cout << "one more clone, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
		*this = other;
	}
}

HumanA &	HumanA::operator=( HumanA const & rhs ) {

	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_weapon.setType(rhs._weapon.getType());
	}
	return *this;
}

///			Functions/Methods

void	HumanA::attack( ) const {

	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;

}

///			Private:

std::ostream &	operator<<(std::ostream & o_stream, HumanA const & human) {

	human.attack();
	return o_stream;
}

int			HumanA::_nb_humanAs_alive = 0;
Weapon *	HumanA::_default_weapon = new Weapon("Avtomat Kalashnikova");
