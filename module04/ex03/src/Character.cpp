#include <iostream>
#include "Character.hpp"

///			Public:

///			Getters / Setters

const std::string &	Character::getName( void ) const {

	return this->_name;
}

AMateria *	Character::getInventory( unsigned int index ) const {

	if (index < MAX_INVENTORY)
		return _inventory[index];
	std::cerr << "[getInventory] index(" << index << ") out of bounds, returning nullptr.." << std::endl;
	return nullptr;
}

///			Constructor / Destructor

Character::Character( const std::string & name )
: _name(name), _inventory() {

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

Character::~Character( ) {

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
	std::cout << "full inventory..<--- remove this!!" << std::endl;
}

void	Character::unequip( int idx ) {


	if (this->_inventory[idx] != nullptr)
	{
		std::cout << "unequipping!!" << std::endl;
		this->_inventory[idx] = nullptr;
		return;
	}
	std::cout << "nothing in _inventory[" << idx << "] to unequip..<--- remove this!!" << std::endl;
}

void	Character::use( int idx, ICharacter &target ) {

	if (this->_inventory[idx] != nullptr)
	{
		std::cout << "using" << target.getName() << std::endl;
		return;
	}
	std::cout << "nothing in _inventory[" << idx << "] to use..<--- remove this!!" << std::endl;
}

void	Character::makeSilent( void ) {

	Character::_loud = false;
}

///			Private:

bool	Character::_loud = true;

