#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "ClassContact.hpp"

# define MAX_CONTACTS 8
# define COL_WIDTH 10

using namespace ::std;

class Phonebook {

public:

	explicit Phonebook( string prompt );
	Phonebook( Phonebook const & src);
	~Phonebook( );

	Phonebook & operator=( Phonebook const & rhs);

	void	makeContact( );
	void	searchPhonebook( ) const;
	string	getPrompt( ) const;
	void	populatePhonebook( );

private:

	Contact	_contacts[MAX_CONTACTS];
	string	const _prompt;

	void 	_addContact( const Contact& new_contact );
	void	_printSearch( ) const;
	Contact _getContact( int i ) const;
	string	_shrink( string ) const;
	string	_readInput( const string& prompt ) const;
};

#endif