#include "HumanB.hpp"

///			Public:

std::string	HumanB::getName( ) const {

	if (this->name.empty())
		return "<no_name>";
	return this->name;
}

void	HumanB::setWeapon( Weapon & new_weapon ) {

	delete this->weapon;
	this->weapon = new Weapon(new_weapon);

}

///			Constructor/Destroyer

HumanB::HumanB( std::string name ) : name(name), weapon(nullptr) {

	HumanB::_nb_humanAs_alive++;
	std::cout << "one more, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;

}

HumanB::HumanB(	) : weapon(nullptr) {

	HumanB::_nb_humanAs_alive++;
	std::cout << "one more, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
}

HumanB::~HumanB( ) {

	delete this->weapon;
	// TODO
	HumanB::_nb_humanAs_alive--;
	std::cout << "one less, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
}

HumanB::HumanB( const HumanB& other ) : name(other.getName()), weapon(nullptr) {

	if (this != &other)
	{
		if (other.weapon)
			this->weapon = new Weapon(other.weapon->getType());
		HumanB::_nb_humanAs_alive++;
		std::cout << "one more clone, HumanB's alive: " << HumanB::_nb_humanAs_alive << std::endl;
	}
}

HumanB &	HumanB::operator=( const HumanB& rhs ) {

	if (this != &rhs)
	{
		this->name = rhs.getName();
		if (rhs.weapon)
			this->weapon = new Weapon(rhs.weapon->getType());
		else
			this->weapon = nullptr;
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

std::ostream & operator<<(std::ostream& o_stream, HumanB & rhs)
{

	return o_stream << rhs.getName();
}