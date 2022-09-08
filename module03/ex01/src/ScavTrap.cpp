#include "ScavTrap.hpp"

///			Public:

///			Getters/Setters

///			Constructor/Destroyer

ScavTrap::ScavTrap( const std::string & name ) : ClapTrap(name) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ScavTrap] Standard constructor called" << std::endl;
    }
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(	) : ClapTrap() {

	if (ClapTrap::_loud)
    {
		std::cout << "[ScavTrap] Default constructor called" << std::endl;
    }
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap & other) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ScavTrap] Copy constructor called" << std::endl;
    }
	if (this != &other)
	{
		*this = other;
	}
}

ScavTrap::~ScavTrap( ) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ScavTrap] Destructor called" << std::endl;
    }
}

ScavTrap &	ScavTrap::operator=( const ScavTrap & rhs ) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ScavTrap] Copy assignment operator called" << std::endl;
    }
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit_points = rhs.getHitPoints();
		this->_energy_points = rhs.getEnergyPoints();
		this->_attack_damage = rhs.getAttackDamage();
	}
	return *this;
}

///			Functions/Methods

void	ScavTrap::attack( const std::string & target ) {

	if (this->_hit_points == 0)
    {
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack.." << std::endl;
    }
	else if (this->_energy_points == 0)
    {
		std::cout << "ScavTrap " << this->_name << " has not enough energy to attack.." << std::endl;
    }
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage" << std::endl;
		this->_energy_points--;
	}
}

void	ScavTrap::guardGate( ) {

	if (this->_hit_points == 0)
    {
		std::cout << "ScavTrap " << this->_name << " is dead and cannot guard.." << std::endl;
    }
	else if (this->_energy_points == 0)
    {
		std::cout << "ScavTrap " << this->_name << " has not enough energy to guard.." << std::endl;
    }
	else
	{
		std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode" << std::endl;
		this->_energy_points--;
	}

}

///			Private:

