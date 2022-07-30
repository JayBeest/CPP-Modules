#include "HumanA.hpp"

///			Public:

///			Constructor/Destroyer

HumanA::HumanA( std::string name, Weapon & weapon )
: name(name), weapon(weapon) {

	HumanA::_nb_humanAs_alive++;
	std::cout << "one more, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;

}

HumanA::HumanA(	) : weapon(*HumanA::_default_weapon){

	HumanA::_nb_humanAs_alive++;
	std::cout << "one more, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
}

HumanA::~HumanA( ) {

	if (HumanA::_nb_humanAs_alive == 1)
		delete HumanA::_default_weapon;
	// TODO
	HumanA::_nb_humanAs_alive--;
	std::cout << "one less, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
}

HumanA::HumanA( const HumanA& other)
: name(other.name), weapon(*new Weapon(other.weapon)) {

	if (this != &other)
	{
		std::cout << "This is weird..:P";
		// TODO
	}
	HumanA::_nb_humanAs_alive++;
	std::cout << "one more clone, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
//	*this = other;
}

HumanA &	HumanA::operator=( const HumanA& rhs ) {

	if (this != &rhs)
	{
		this->name = rhs.name;
		this->weapon.setType(rhs.weapon.getType());
	}
	return *this;
}

///			Functions/Methods

void	HumanA::attack( ) const {

	std::cout << this->name	<< " attacks with their " << this->weapon.getType() << std::endl;

}

///			Private:

int			HumanA::_nb_humanAs_alive = 0;
Weapon *	HumanA::_default_weapon = new Weapon("Avtomat Kalashnikova");