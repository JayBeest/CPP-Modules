#include "ClassContact.hpp"
#include <iostream>

using namespace ::std;

int	Contact::_nb_contacts = 0;

Contact::Contact ( string f, string l, string n, string p, string d )
	: _firstN(f), _lastN(l), _nickN(n), _phoneN(p), _darkS(d) {

	if (Contact::_nb_contacts < 8)
		Contact::_nb_contacts++;

}

Contact::Contact ( Contact const & other ){

	*this = other;
}

Contact::~Contact( ) {

}

Contact &	Contact::operator=( Contact const & rhs ){

	this->_firstN = rhs.getFirstN( );
	this->_lastN = rhs.getLastN( );
	this->_nickN = rhs.getNickN( );
	this->_phoneN = rhs.getPhoneN( );
	this->_darkS = rhs.getDarkS( );

	return *this;
}

string	Contact::getFirstN( ) const {

	return this->_firstN;
}

string	Contact::getLastN( ) const {

	return this->_lastN;
}

string	Contact::getNickN( ) const {

	return this->_nickN;
}

string	Contact::getPhoneN( ) const {

	return this->_phoneN;
}

string	Contact::getDarkS( ) const {

	return this->_darkS;
}

int	Contact::get_nbContacts( ) const {

	return Contact::_nb_contacts;
}

Contact::Contact( ) {

}
