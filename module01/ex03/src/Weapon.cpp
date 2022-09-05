#include <string>
#include "Weapon.hpp"

///			Public:

///			Getters/Setters

const	std::string & Weapon::getType( ) const {

	return this->_type;
}

void	Weapon::setType( const std::string & type )  {

	this->_type = type;
}

///			Constructor/Destroyer

Weapon::Weapon( const std::string & type ) : _type(type) {

}

Weapon::Weapon(	) : _type("<no_type>") {

}

Weapon::~Weapon( ) {

}

Weapon::Weapon( const Weapon & other ) {

	if (this != &other)
	{
        *this = other;
	}
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
