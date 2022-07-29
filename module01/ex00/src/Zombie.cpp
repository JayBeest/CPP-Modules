#include "Zombie.hpp"

///			Public:

int		ClassZombie::getId( ) const {

	return this->_id;
}

int		ClassZombie::getVars( ) const {

	return this->_vars;
}

int		ClassZombie::getNb_ClassZombie_created( ) const {

	return ClassZombie::_nb_ClassZombie_created;
}

///			Constructor/Destroyer

ClassZombie::ClassZombie( int args ) : _vars(args) {

	this->_id = _nb_ClassZombie_created++;
}

ClassZombie::ClassZombie(	) {

										// TODO not counting default constructor

}

ClassZombie::ClassZombie( const ClassZombie& other) {

	if (this != &other)
	{
		this->_vars = other.getVars();	// TODO
	}
	*this = other;
}

ClassZombie::~ClassZombie( ) {

	// TODO

}

ClassZombie &	ClassZombie::operator=( const ClassZombie& rhs ) {

	if (this != &rhs)
	{
		this->_vars = rhs.getVars();	// TODO
	}
	return *this;
}

///			Functions/Methods

void	ClassZombie::doStuff( ) const {

	// TODO

}

///			Private:



int	ClassZombie::_nb_ClassZombie_created = 0;
