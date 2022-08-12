#include <iostream>
#include "MateriaSource.hpp"

///			Public:

///			Getters / Setters

///			Constructor / Destructor

MateriaSource::MateriaSource( ) : _source_inventory() {

	if (AMateria::_loud)
  		std::cout << "[MateriaSource] Default constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& other) {

	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
	if (AMateria::_loud)
  		std::cout << "[MateriaSource] Copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource( ) {

	for (int i = 0; i < MAX_SOURCE_INV; i++)
		delete this->_source_inventory[i];
	if (AMateria::_loud)
  		std::cout << "[MateriaSource] Destructor called" << std::endl;
}

MateriaSource &	MateriaSource::operator=( const MateriaSource& rhs ) {

	if (this != &rhs)
	{
//		this->_vars = rhs.getVars();	// TODO
	}
	if (AMateria::_loud)
  		std::cout << "[MateriaSource] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	MateriaSource::learnMateria( AMateria * materia ) {

	static int i = 0;

	if (i < MAX_SOURCE_INV)
	{
		std::cout << "Storing " << *materia << " in source_inventory(" << i << ")" << std::endl;
		delete this->_source_inventory[i];
		this->_source_inventory[i] = materia;
		i++;
	}
	else
	{
		i = 0;
		std::cout << "Source_inventory full, overwriting oldest materia(" << i << ") with: " << *materia << std::endl;
		delete this->_source_inventory[i];
		this->_source_inventory[i] = materia;
	}
}

AMateria *	MateriaSource::createMateria( const std::string & type ) {

	for (int i = 0; i < MAX_SOURCE_INV; i++)
	{
		if (_source_inventory[i]->getType() == type)
			return _source_inventory[i]->clone();
	}
	std::cout << "Materia-type " << type << " not found.." << std::endl;
	return nullptr;
}

void	MateriaSource::makeSilent( void ) {

	AMateria::_loud = false;
}

///			Private:

