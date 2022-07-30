#include "HumanB.hpp"

///			Public:

bool	HumanB::verbose = false;

///			Getters/Setters

std::string	HumanB::getName( ) const {

	if (this->name.empty())
		return "<no_name>";
	return this->name;
}

void	HumanB::setWeapon( Weapon const & new_weapon ) {

	delete this->weapon;
	this->weapon = new Weapon(new_weapon);

}

///			Constructor/Destroyer

HumanB::HumanB( std::string const & name )
: name(name), weapon(nullptr) {

	HumanB::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;

}

HumanB::HumanB(	)
: name(""), weapon(nullptr) {

	HumanB::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
}

HumanB::~HumanB( ) {

	delete this->weapon;
	// TODO
	HumanB::_nb_humanAs_alive--;
	if (verbose)
		std::cout << "one less, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
}

HumanB::HumanB( HumanB const & other )
: name(other.getName()), weapon(nullptr) {

	if (this != &other)
	{
		if (other.weapon)
			this->weapon = new Weapon(other.weapon->getType());
		HumanB::_nb_humanAs_alive++;
		if (verbose)
			std::cout << "one more clone, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
	}
}

HumanB &	HumanB::operator=( HumanB const & rhs ) {

	if (this != &rhs)
	{
		delete this->weapon;
		if (this->weapon)
			std::cout << std::endl << std::endl << "WEAPON = nullptr" << std::endl << std::endl;
		this->name = rhs.getName();
		if (rhs.weapon)
			this->weapon = new Weapon(rhs.weapon->getType());

	}
	return *this;
}

///			Functions/Methods

void	HumanB::attack( ) const {

	std::cout << this->getName();
	if (this->weapon)
		std::cout << " attacks with their " << this->weapon->getType();
	else
		std::cout << " has no weapon..:(";
	std::cout << std::endl;

}

///			Private:

int			HumanB::_nb_humanAs_alive = 0;

std::ostream & operator<<(std::ostream & o_stream, HumanB const & human)
{

	human.attack();
	return o_stream;
}