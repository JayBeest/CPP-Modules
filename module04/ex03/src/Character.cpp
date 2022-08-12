#include <iostream>
#include "Character.hpp"

///			Public:

///			Getters / Setters

const std::string &	Character::getName( void ) const {

	return this->_name;
}

///			Constructor / Destructor

Character::Character( const std::string & name )
: _name(name), _inventory(), _ground() {

	if (Character::_loud)
  		std::cout << "[Character] Specific constructor called" << std::endl;
}

Character::Character( ) {

										// TODO not counting default constructor
	if (Character::_loud)
  		std::cout << "[Character] Default constructor called" << std::endl;
}

Character::Character( const Character& other) {

	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
	if (Character::_loud)
  		std::cout << "[Character] Copy constructor called" << std::endl;
}

Character::~Character( void ) {

	// TODO
	if (Character::_loud)
  		std::cout << "[Character] Destructor called" << std::endl;
}

Character &	Character::operator=( const Character& rhs ) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();	// TODO
	}
	if (Character::_loud)
  		std::cout << "[Character] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	Character::equip( AMateria *m ) {

	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			std::cout << "equipping!!" << std::endl;
			return;
		}
	}
	std::cout << "full inventory..deleting AMateria<--- remove this!!" << std::endl;
	delete m;
}

void	Character::unequip( int idx ) {


	if (this->_inventory[idx] != nullptr)
	{
		std::cout << "unequipping!!" << std::endl;
		dropToGround(this->_inventory[idx]);
		this->_inventory[idx] = nullptr;
		return;
	}
	std::cout << "nothing in _inventory[" << idx << "] to unequip..<--- remove this!!" << std::endl;
}

void	Character::use( int idx, ICharacter &target ) {

	if (this->_inventory[idx] == nullptr)
	{
		std::cout << "nothing in _inventory[" << idx << "] to use..<--- remove this!!" << std::endl;
		return;
	}
	if (this->getInventory(idx)->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->getInventory(idx)->getType() == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *	Character::getInventory( unsigned int index ) const {

	if (index < MAX_INVENTORY)
		return _inventory[index];
	std::cerr << "[getInventory] index(" << index << ") out of bounds, returning nullptr.." << std::endl;
	return nullptr;
}

void	Character::makeSilent( void ) {

	Character::_loud = false;
}

///			Private:

void	Character::dropToGround( AMateria *materia ) {

	static int	i = 0;

	if  (i < MAX_GROUND)
	{
		delete this->_ground[i];
		this->_ground[i] = materia;
		std::cout << "dropped on ground(" << i << ")" << std::endl;
		i++;
	}
	else
	{
		std::cout << "no free spot, resetting ground_counter" << std::endl;
		i = 0;
		delete this->_ground[i];
		this->_ground[i] = materia;
	}
}

bool	Character::_loud = true;

