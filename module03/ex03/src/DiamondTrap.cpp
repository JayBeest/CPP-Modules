#include "DiamondTrap.hpp"

///			Public:

///			Getters/Setters

std::string 	DiamondTrap::getName( void ) const {

	return this->_name;
}

///			Constructor/Destroyer

DiamondTrap::DiamondTrap( const std::string & name )
: ClapTrap(name + "_clap_name"), _name(name) {

	this->_hit_points = this->FragTrap::_hit_points;
	this->_energy_points = this->ScavTrap::_energy_points;
	this->_attack_damage = this->FragTrap::_attack_damage;
	// attack() overloading!?
	if (ClapTrap::_loud)
		std::cout << "[DiamondTrap] Standard constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( ) {

	if (ClapTrap::_loud)
		std::cout << "[DiamondTrap] Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other) {

	if (this != &other)
	{
		*this = other;
	}
	if (ClapTrap::_loud)
		std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( ) {

	if (ClapTrap::_loud)
		std::cout << "[DiamondTrap] Destructor called" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=( const DiamondTrap& rhs ) {

	if (this != &rhs)
	{
		this->ClapTrap::_name = rhs.ClapTrap::getName(); //test name stuff!!
		this->_name = rhs.getName();
		this->_hit_points = rhs.getHitPoints();
		this->_energy_points = rhs.getEnergyPoints();
		this->_attack_damage = rhs.getAttackDamage();
	}
	if (ClapTrap::_loud)
		std::cout << "[DiamondTrap] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions/Methods

void	DiamondTrap::whoAmI( void ) const {

	std::cout << "DiamondTrap " << this->_name << "'s ClapTrap name is: " << this->ClapTrap::_name << std::endl;
}

///			Private:

