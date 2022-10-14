#include "ScavTrap.hpp"

///			Public:

///			Getters/Setters

///			Constructor/Destroyer

ScavTrap::ScavTrap( const std::string & name ) : ClapTrap(name) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ScavTrap] Standard constructor called" << std::endl;
    }
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(	) : ClapTrap() {

	if (ClapTrap::_loud)
    {
		std::cout << "[ScavTrap] Default constructor called" << std::endl;
    }
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
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
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

///			Functions/Methods

void	ScavTrap::attack( const std::string & target ) {

	if (this->_hitPoints == 0)
    {
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack.." << std::endl;
    }
	else if (this->_energyPoints == 0)
    {
		std::cout << "ScavTrap " << this->_name << " has not enough energy to attack.." << std::endl;
    }
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate( ) {

	if (this->_hitPoints == 0)
    {
		std::cout << "ScavTrap " << this->_name << " is dead and cannot guard.." << std::endl;
    }
	else if (this->_energyPoints == 0)
    {
		std::cout << "ScavTrap " << this->_name << " has not enough energy to guard.." << std::endl;
    }
	else
	{
		std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode" << std::endl;
		this->_energyPoints--;
	}

}

///			Private:

