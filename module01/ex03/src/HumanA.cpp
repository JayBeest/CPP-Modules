#include "HumanA.hpp"

///			Public:

bool	HumanA::verbose = false;

///			Getters/Setters

///			Constructor/Destroyer

HumanA::HumanA( std::string const & name, Weapon & weapon )
: name(name), weapon(weapon) {

	HumanA::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;

}

HumanA::HumanA(	)
: name(""), weapon(*HumanA::_default_weapon){

	HumanA::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
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
: name(other.name), weapon(*HumanA::_default_weapon){

	if (this != &other)
	{
		HumanA::_nb_humanAs_alive++;
		if (verbose)
			std::cout << "one more clone, HumanA's alive: " << HumanA::_nb_humanAs_alive << std::endl;
		// TODO
	}
}

HumanA &	HumanA::operator=( HumanA const & rhs ) {

	if (this != &rhs)
	{
		this->name = rhs.name;
		this->weapon.setType(rhs.weapon.getType());
	}
	return *this;
}

///			Functions/Methods

void	HumanA::attack( ) const {

	if (this->name.empty())
		std::cout << "<no_name>";
	else
		std::cout << this->name;
	std::cout << " attacks with their " << this->weapon.getType() << std::endl;

}

///			Private:

int			HumanA::_nb_humanAs_alive = 0;
Weapon *	HumanA::_default_weapon = new Weapon("Avtomat Kalashnikova");

std::ostream &	operator<<(std::ostream & o_stream, HumanA const & human) {

	human.attack();
	return o_stream;
}
