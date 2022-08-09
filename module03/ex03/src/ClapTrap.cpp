#include "ClapTrap.hpp"

///			Public:

///			Getters/Setters

std::string	ClapTrap::getName( void ) const {

	return this->_name;
}

unsigned int	ClapTrap::getHitPoints( void ) const {

	return this->_hit_points;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {

	return this->_energy_points;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {

	return this->_attack_damage;
}

void			ClapTrap::setAttackDamage( unsigned int damage ) {

	this->_attack_damage = damage;
}

///			Constructor/Destroyer

ClapTrap::ClapTrap( const std::string & name )
: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {

	if (ClapTrap::_loud)
		std::cout << "[ClapTrap] Standard constructor called" << std::endl;
}

ClapTrap::ClapTrap(	)
: _name("<no_name>"), _hit_points(10), _energy_points(10), _attack_damage(0) {

	if (ClapTrap::_loud)
		std::cout << "[ClapTrap] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other) {

	if (this != &other)
	{
		*this = other;
	}
	if (ClapTrap::_loud)
		std::cout << "[ClapTrap] Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap( ) {

	if (ClapTrap::_loud)
		std::cout << "[ClapTrap] Destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=( const ClapTrap& rhs ) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit_points = rhs.getHitPoints();
		this->_energy_points = rhs.getEnergyPoints();
		this->_attack_damage = rhs.getAttackDamage();
	}
	if (ClapTrap::_loud)
		std::cout << "[ClapTrap] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions/Methods

void	ClapTrap::attack( const std::string & target) {

	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->getName() << " is dead and cannot attack.." << std::endl;
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->getName() << " has not enough energy to attack.." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << this->_attack_damage << " points of damage" << std::endl;
		this->_energy_points--;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	unsigned int	damage = 0;

	if (amount > this->_hit_points)
		damage = this->_hit_points;
	else
		damage = amount;
	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->getName() << " is already dead.." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " takes " << damage << " point(s) of damage." << std::endl;
		if (this->_hit_points > amount)
			this->_hit_points -= amount;
		else
			this->_hit_points = 0;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repair itself.." << std::endl;
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->_name << " has not enough energy to repair itself.." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	}
}

void	ClapTrap::makeSilent( void ) {

	ClapTrap::_loud = false;
}

///			Private:

bool	ClapTrap::_loud = true;
