#include "FragTrap.hpp"

///			Public:

///			Getters/Setters

///			Constructor/Destroyer

FragTrap::FragTrap( const std::string & name ) : ClapTrap(name) {

	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	if (ClapTrap::_loud)
		std::cout << "[FragTrap] Standard constructor called" << std::endl;
}

FragTrap::FragTrap(	) {

	if (ClapTrap::_loud)
		std::cout << "[FragTrap] Default constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& other) {

	if (this != &other)
	{
		*this = other;
	}
	if (ClapTrap::_loud)
		std::cout << "[FragTrap] Copy constructor called" << std::endl;
}

FragTrap::~FragTrap( ) {

	if (ClapTrap::_loud)
		std::cout << "[FragTrap] Destructor called" << std::endl;
}

FragTrap &	FragTrap::operator=( const FragTrap& rhs ) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit_points = rhs.getHitPoints();
		this->_energy_points = rhs.getEnergyPoints();
		this->_attack_damage = rhs.getAttackDamage();
	}
	if (ClapTrap::_loud)
		std::cout << "[FragTrap] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions/Methods

void	FragTrap::highFivesGuys( void ) {

	if (this->_hit_points == 0)
		std::cout << "FragTrap " << this->_name << " is dead and cannot high-five.." << std::endl;
	else if (this->_energy_points == 0)
		std::cout << "FragTrap " << this->_name << " has not enough energy to high-five.." << std::endl;
	else
	{
		std::cout << "FragTrap " << this->_name << " blurts out: 'High-five! C'mon robots! High-five!'" << std::endl;
		this->_energy_points--;
	}
}

///			Private:

