#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "CLassContact.hpp"

# define MAX_CONTACTS 8
# define COL_WIDTH 10
# define PROMPT "P-42: "

class Phonebook {

public:

	bool			empty( ) const;
	std::string		get_prompt( ) const;

	explicit		Phonebook( std::string prompt );
					Phonebook( Phonebook const & src );
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