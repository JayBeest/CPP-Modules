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
: _name(name), _weapon(nullptr) {

	HumanB::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
}

HumanB::HumanB(	)
: _name("<no_name>"), _weapon(nullptr) {

	HumanB::_nb_humanAs_alive++;
	if (verbose)
		std::cout << "one more, HumanB's alive (default): " << HumanB::_nb_humanAs_alive << std::endl;
}

HumanB::~HumanB( ) {

	delete this->_weapon;
	// TODO
	HumanB::_nb_humanAs_alive--;
	if (verbose)
		std::cout << "one less, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
}

HumanB::HumanB( HumanB const & other )
: _name(other.getName()), _weapon(nullptr) {

	if (this != &other)
	{
		HumanB::_nb_humanAs_alive++;
        *this = other;
		if (verbose)
			std::cout << "one more clone, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
	}
}

HumanB &	HumanB::operator=( HumanB const & rhs ) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		delete this->_weapon;
		if (rhs._weapon)
			this->_weapon = new Weapon(rhs._weapon->getType());
		else
			this->_weapon = nullptr;
	}
	return *this;
}

///			Functions/Methods

void	HumanB::attack( ) const {

	std::cout << this->getName();
	if (this->_weapon)
		std::cout << " attacks with their " << this->_weapon->getType();
	else
		std::cout << " has no weapon..:(";
	std::cout << std::endl;
}

///			Private:

std::ostream & operator<<(std::ostream & o_stream, HumanB const & human)
{

	human.attack();
	return o_stream;
}

int			HumanB::_nb_humanAs_alive = 0;
