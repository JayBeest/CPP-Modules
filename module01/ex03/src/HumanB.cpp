#include "HumanB.hpp"

///			Public:

bool	HumanB::verbose = false;

///			Getters/Setters

std::string	HumanB::getName( ) const {

	return this->_name;
}

void	HumanB::setWeapon( Weapon const & new_weapon ) {

	delete this->_weapon;
	this->_weapon = new Weapon(new_weapon);
}

///			Constructor/Destroyer

HumanB::HumanB( std::string const & name )
: _name(name), _weapon(NULL) {

	HumanB::_nb_humanAs_alive++;
	if (verbose)
    {
		std::cout << "one more, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
    }
}

HumanB::~HumanB( ) {

	delete this->_weapon;
	HumanB::_nb_humanAs_alive--;
	if (verbose)
    {
		std::cout << "one less, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
    }
}

///			Functions/Methods

void	HumanB::attack( void ) const {

	std::cout << this->getName();
	if (this->_weapon)
    {
		std::cout << " attacks with their " << this->_weapon->getType();
    }
	else
    {
		std::cout << " has no weapon..:(";
    }
	std::cout << std::endl;
}

///			Private:

std::ostream & operator<<( std::ostream & o_stream, HumanB const & human ) {

	human.attack();
	return o_stream;
}

int			HumanB::_nb_humanAs_alive = 0;
