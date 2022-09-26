#include "HumanA.hpp"

///			Public:

///			Getters/Setters

const std::string &	HumanA::getName( void ) const {

    return this->_name;
}

///			Constructor/Destroyer

HumanA::HumanA( const std::string & name, Weapon & weapon )
: _name(name), _weapon(weapon) {

}

HumanA::~HumanA( ) {

}

///			Functions/Methods

void	HumanA::attack( ) const {

	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

///			Private:

std::ostream &	operator<<( std::ostream & o_stream, const HumanA & human ) {

	human.attack();
	return o_stream;
}
