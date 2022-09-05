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

HumanA::~HumanA( ) {

	// TODO
	HumanA::_nb_humanAs_alive--;
	if (verbose)
		std::cout << "one less, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
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
