#include "ClapTrap.hpp"

///			Public:

///			Getters/Setters

const std::string &	ClapTrap::getName( ) const {

	return this->_name;
}

unsigned int		ClapTrap::getHitPoints( ) const {

	return this->_hitPoints;
}

unsigned int		ClapTrap::getEnergyPoints( ) const {

	return this->_energyPoints;
}

unsigned int		ClapTrap::getAttackDamage( ) const {

	return this->_attackDamage;
}

void			ClapTrap::setAttackDamage( unsigned int damage ) {

	this->_attackDamage = damage;
}

///			Constructor/Destroyer

ClapTrap::ClapTrap( const std::string & name )
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ClapTrap] Standard constructor called" << std::endl;
    }
}

ClapTrap::ClapTrap(	)
: _name("<no_name>"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ClapTrap] Default constructor called" << std::endl;
    }
}

ClapTrap::ClapTrap( const ClapTrap & other ) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ClapTrap] Copy constructor called" << std::endl;
    }
	if (this != &other)
	{
		*this = other;
	}
}

ClapTrap::~ClapTrap( ) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ClapTrap] Destructor called" << std::endl;
    }
}

ClapTrap &	ClapTrap::operator=( const ClapTrap & rhs ) {

	if (ClapTrap::_loud)
    {
		std::cout << "[ClapTrap] Copy assignment operator called" << std::endl;
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

void	ClapTrap::attack( const std::string & target) {

	if (this->_hitPoints == 0)
    {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack.." << std::endl;
    }
	else if (this->_energyPoints == 0)
    {
		std::cout << "ClapTrap " << this->_name << " has not enough energy to attack.." << std::endl;
    }
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	unsigned int	damage = 0;

	if (amount > this->_hitPoints)
		damage = this->_hitPoints;
	else
		damage = amount;
	if (this->_hitPoints == 0)
    {
		std::cout << "ClapTrap " << this->_name << " is already dead.." << std::endl;
    }
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << damage << " point(s) of damage." << std::endl;
		if (this->_hitPoints > amount)
			this->_hitPoints -= amount;
		else
			this->_hitPoints = 0;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	if (this->_hitPoints == 0)
    {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repair itself.." << std::endl;
    }
	else if (this->_energyPoints == 0)
    {
		std::cout << "ClapTrap " << this->_name << " has not enough energy to repair itself.." << std::endl;
    }
	else
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}

void	ClapTrap::makeSilent( ) {

	ClapTrap::_loud = false;
}

///			Private:

bool	ClapTrap::_loud = true;
