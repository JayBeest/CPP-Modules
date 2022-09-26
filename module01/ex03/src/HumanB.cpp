#include "HumanB.hpp"

///			Public:

///			Getters/Setters

std::string	HumanB::getName( ) const {

	return this->_name;
}

void	HumanB::setWeapon( const Weapon & new_weapon ) {

	delete this->_weapon;
	this->_weapon = new Weapon(new_weapon);
}

///			Constructor/Destroyer

HumanB::HumanB( const std::string & name )
: _name(name), _weapon(NULL) {

}

HumanB::~HumanB( ) {

	delete this->_weapon;
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

std::ostream & operator<<( std::ostream & o_stream, const HumanB & human ) {

	human.attack();
	return o_stream;
}
