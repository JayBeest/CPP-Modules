#include "ClassContact.hpp"
#include "ClassPhonebook.hpp"

Contact::Contact( std::string f, std::string l, std::string n, std::string p, std::string d )
	: _firstN(f), _lastN(l), _nickN(n), _phoneN(p), _darkS(d) {

	Contact::_nb_contacts++;
}

Contact::Contact( Contact const & other ) {

	if (this != &other)
		*this = other;
}

Contact::~Contact( ) {

}

Contact &	Contact::operator=( Contact const & rhs ) {

	this->_firstN = rhs.getFirstN( );
	this->_lastN = rhs.getLastN( );
	this->_nickN = rhs.getNickN( );
	this->_phoneN = rhs.getPhoneN( );
	this->_darkS = rhs.getDarkS( );
	return *this;
}

std::string	Contact::getFirstN( ) const {

	return this->_firstN;
}

std::string	Contact::getLastN( ) const {

	return this->_lastN;
}

std::string	Contact::getNickN( ) const {

	return this->_nickN;
}

std::string	Contact::getPhoneN( ) const {

	return this->_phoneN;
}

std::string	Contact::getDarkS( ) const {

	return this->_darkS;
}

int	Contact::get_nbContacts( ) {

	return Contact::_nb_contacts;
}

Contact::Contact( )
	: _firstN("<empty_contact>"), _lastN("<empty_contact>"), _nickN("<empty_contact>"), _phoneN("<empty_contact>"), _darkS("<empty_contact>") {

}

int	Contact::_nb_contacts = 0;
