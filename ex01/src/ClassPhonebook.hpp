#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "ClassContact.hpp"

# define MAX_CONTACTS 8
# define COL_WIDTH 10

using namespace std;

class Phonebook {

public:

	Phonebook( void );
	Phonebook( Phonebook const & src);
	~Phonebook( void );

	Phonebook & operator=( Phonebook const & rhs);

	void	makeContact( void );
	void	searchPhonebook(void ) const;
	void	populatePhonebook( void );

private:

	Contact	_contacts[MAX_CONTACTS];

	void 	_addContact( Contact newContact );
	void	_printSearch(void ) const;
	Contact _getContact( int i ) const;
	string	_shrink( string ) const;
	string	_readInput( string const prompt ) const;
};

#endif