#include <string>
#include "Weapon.hpp"

///			Public:

///			Getters/Setters

const	std::string & Weapon::getType( ) const {

	return this->_type;
}

void	Weapon::setType( std::string const & type )  {

	this->_type = type;

}

///			Constructor/Destroyer

Weapon::Weapon( std::string const & type ) : _type(type) {

}

Weapon::Weapon(	) {

}

Weapon::~Weapon( ) {

}

Weapon::Weapon( Weapon const & other) {

	if (this != &other)
	{
		this->_type = other.getType();
	}
	*this = other;
}

Weapon &	Weapon::operator=( Weapon const & rhs ) {

	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

///			Functions/Methods

///			Private:
