#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "ClassContact.hpp"

# define MAX_CONTACTS 8
# define COL_WIDTH 10
# define PROMPT "P-42: "

class Phonebook {

public:

	bool			empty( ) const;
	std::string		get_prompt( ) const;

	explicit		Phonebook( std::string prompt );
					Phonebook( const Phonebook& src );
					~Phonebook( );
					Phonebook& operator=( const Phonebook& rhs);

	std::string		readInput(std::string prompt ) const;
	void			printUsage( ) const;
	void			searchPhonebook( ) const;
	void			makeContact( );
	void			populatePhonebook( );

private:

	bool			_empty;
	std::string		_prompt;
	Contact			_contacts[MAX_CONTACTS];

	void 			_addContact( const Contact& new_contact );
	void			_printContact( const Contact& to_print) const;
	void			_printSearch( ) const;
	Contact			_getContact( int i ) const;
	std::string		_shrink( std::string ) const;

};

#endif