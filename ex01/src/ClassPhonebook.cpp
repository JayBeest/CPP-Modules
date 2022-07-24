#include <iostream>
#include <iomanip>
#include <math.h>
#include "ClassPhonebook.hpp"

using namespace ::std;

Phonebook::Phonebook( void ) {

	return;
}

Phonebook::Phonebook( Phonebook const & other) {

	*this = other;
	return;
}

Phonebook::~Phonebook( void ) {

	return;
}

Phonebook &		Phonebook::operator=( Phonebook const & rhs) {

	for (int i = 0; i < MAX_CONTACTS; i++)
		this->_contacts[i] = rhs._getContact(i);
	return *this;
}

void		Phonebook::makeContact( void ){

	string	first_name;
	string	last_name;
	string	nick_name;
	string	phone_nb;
	string	dark_secret;

	first_name = _readInput("Input first name: ");
	last_name = _readInput("Input last name: ");
	nick_name = _readInput("Input nickname: ");
	phone_nb = _readInput("Input phone number: ");
	dark_secret = _readInput("Input dark secret: ");

	this->_addContact(Contact(first_name, last_name, nick_name, phone_nb, dark_secret));

	return;
}

void	Phonebook::_printSearch(void ) const {

	cout << setw(COL_WIDTH) << "index"
		<< setw(COL_WIDTH) << "first name"
		<< setw(COL_WIDTH) << "last name"
		<< setw(COL_WIDTH) << "nickname"
		<< endl;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		cout << setw(COL_WIDTH) << i
		<< setw(COL_WIDTH) << _shrink(this->_contacts[i].getFirstN()) << "|"
		<< setw(COL_WIDTH) << _shrink(this->_contacts[i].getLastN()) << "|"
		<< setw(COL_WIDTH) << _shrink(this->_contacts[i].getNickN()) << "|"
		<< endl;
	}

	return;
}

void	Phonebook::searchPhonebook(void ) const {

	string	cmd;
	size_t i = 0;

	this->_printSearch();
	while (1)
	{
		cout << "Input index: ";
		getline(cin, cmd);
		while (i < cmd.size() && isdigit(cmd[i]))
			i++;
		if (i != cmd.size())
		{
			cout << "non-digit detected." << endl;
			this->_printSearch();
			continue;
		}
		i = atoi(cmd.c_str());
		if (i >= 0 && i < MAX_CONTACTS)
		{
			cout << setw(10) << "Index: " << i << endl
			<< setw(10) << "First name: " << this->_contacts->getFirstN() << endl
			<< setw(10) << "Last name: " << this->_contacts->getFirstN() << endl
			<< setw(10) << "Nickname: " << this->_contacts->getFirstN() << endl
			<< setw(10) << "Phone number: " << this->_contacts->getFirstN() << endl
			<< setw(10) << "Dark Secret: " << this->_contacts->getFirstN() << endl;
			return;
		}
	}


}

void	Phonebook::populatePhonebook( void ) {

	this->_addContact(Contact("Jay Bart", "Cornelisse", "JayBeest", "06xxxxxx57", "jbjbjbjbjbjbjb"));
	this->_addContact(Contact("Dwayne", "Cornelisse", "Dwappa", "06xxxxxx43", "dddddddddddddddddd"));
	this->_addContact(Contact("Frans Bart", "Cornelisse", "FB", "06xxxxxx81", "fbfbfbfbfbfbfbfb"));
	this->_addContact(Contact("Pauline", "de Vries", "Ploon", "06xxxxxx12", "PPPPPPPPPPPPPPPPPP"));
	this->_addContact(Contact("Mary Love", "Cornelisse", "ML", "06xxxxxx53", "mlmlmlmlmlmlmlmlmlml"));
	this->_addContact(Contact("Michael", "Jackson", "MJ", "06xxxxxx91", "ouw!"));
	this->_addContact(Contact("Max", "Verstappen", "SuperMax", "06xxxxxx33", "maxmaxmaxmaxmax"));
	this->_addContact(Contact("Lewis", "Hammilton", "Hammertime", "06xxxxxx45", "hamhamhamha
	return;
}

string	Phonebook::_shrink( string src ) const {

	if (src.size() > 10)
	{
		src.resize(10);
		src[9] = '.';
	}

	return src;
}

void	Phonebook::_addContact(Contact newContact) {

	if (newContact.get_nbContacts() > MAX_CONTACTS)
		this->_contacts[MAX_CONTACTS - 1] = newContact;
	else
		this->_contacts[newContact.get_nbContacts() - 1] = newContact;

		return;
}

Contact		Phonebook::_getContact(int i ) const {

	return this->_contacts[i];
}


string	Phonebook::_readInput( string const prompt ) const {

	string	buffer;

	while (buffer.empty() && buffer[0] !='\n')
	{
		cout << prompt;
		getline(cin, buffer);
	}
	return buffer;
}