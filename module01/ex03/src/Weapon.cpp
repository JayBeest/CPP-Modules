#include <string>
#include "Weapon.hpp"

///			Public:

const	std::string & Weapon::getType( ) const {

	return this->_type;
}

void	Weapon::setType( std::string type )  {

	this->_type = type;

}

///			Constructor/Destroyer

Weapon::Weapon( const std::string type ) : _type(type) {

}

Weapon::Weapon(	) {

}

Weapon::~Weapon( ) {

}

Weapon::Weapon( const Weapon& other) {

	if (this != &other)
	{
		this->_type = other.getType();
	}
	*this = other;
}

Weapon &	Weapon::operator=( const Weapon& rhs ) {

	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

///			Functions/Methods

///			Private:
