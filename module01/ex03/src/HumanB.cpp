#include "HumanB.hpp"

///			Public:

int		HumanB::getId( ) const {

	return this->_id;
}

int		HumanB::getVars( ) const {

	return this->_vars;
}

int		HumanB::getNb_HumanB_created( ) {

	return HumanB::_nb_HumanB_created;
}

///			Constructor/Destroyer

HumanB::HumanB( int args ) : _vars(args) {

	this->_id = _nb_HumanB_created++;
}

HumanB::HumanB(	) {

										// TODO not counting default constructor

}

HumanB::HumanB( const HumanB& other) {

	if (this != &other)
	{
		this->_vars = other.getVars();	// TODO
	}
	*this = other;
}

HumanB::~HumanB( ) {

	// TODO

}

HumanB &	HumanB::operator=( const HumanB& rhs ) {

	if (this != &rhs)
	{
		this->_vars = rhs.getVars();	// TODO
	}
	return *this;
}

///			Functions/Methods

void	HumanB::doStuff( ) const {

	// TODO

}

///			Private:



int	HumanB::_nb_HumanB_created = 0;
