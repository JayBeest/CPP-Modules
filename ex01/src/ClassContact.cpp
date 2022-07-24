#include "ClassContact.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Contact::Contact ( string f, string l, string n, string p, string d )
	: _firstN(f), _lastN(l), _nickN(n), _phoneN(p), _darkS(d) {

	this->_nb_contacts_constructed++;

	return;
}

Contact::Contact ( Contact const & other ){

	*this = other;

	return;
}

Contact::~Contact( void ) {

	return;
}

Contact &	Contact::operator=( Contact const & rhs ){

	this->_firstN = rhs.getFirstN();
	this->_lastN = rhs.getLastN();
	this->_nickN = rhs.getNickN();
	this->_phoneN = rhs.getPhoneN();
	this->_darkS = rhs.getDarkS();

	return *this;
}

string	Contact::getFirstN( void ) const {

	return this->_firstN;
}

string	Contact::getLastN( void ) const {

	return this->_lastN;
}

string	Contact::getNickN( void ) const {

	return this->_nickN;
}

string	Contact::getPhoneN( void ) const {

	return this->_phoneN;
}

string	Contact::getDarkS( void ) const {

	return this->_darkS;
}

int	Contact::get_nbContacts( void ) const {

	return this->_nb_contacts_constructed;
}

Contact::Contact( void ) {

	return;
}

int	Contact::_nb_contacts_constructed = 0;

