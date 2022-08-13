#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# define PROMPT "P-42: "
# define MAX_CONTACTS 8
# define COL_WIDTH 10

# include <iostream>
# include "ClassContact.hpp"

class Phonebook {

public:

	bool			empty( ) const;
	std::string		get_prompt( ) const;

	explicit		Phonebook( const std::string & prompt );
					Phonebook( Phonebook const & other );
					~Phonebook( );
					Phonebook & operator=( Phonebook const & rhs );

	std::string		readInput( std::string prompt ) const;
	void			printUsage( ) const;
	void			searchPhonebook( ) const;
	void			makeContact( );
	void			populatePhonebook( );

private:

	bool			_empty;
	std::string		_prompt;
	Contact			_contacts[MAX_CONTACTS];

	void 			_addContact( Contact const & new_contact );
	void			_printContact( Contact const & to_print ) const;
	void			_printSearch( ) const;
	Contact			_getContact( int i ) const;
	std::string		_shrink( std::string ) const;

};

#endif
