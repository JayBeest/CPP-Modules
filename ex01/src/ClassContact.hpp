#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

using namespace ::std;

class Contact {


public:

	Contact( string f, string l, string n, string p, string d);
	Contact( Contact const & other);
	Contact( );
	~Contact ( );

	Contact &	operator=( Contact const & rhs );

	string	getFirstN ( ) const;
	string	getLastN ( ) const;
	string	getNickN ( ) const;
	string	getPhoneN ( ) const;
	string	getDarkS ( ) const;
	int		get_nbContacts ( ) const;

private:

	static int	_nb_contacts;

	string	_firstN;
	string	_lastN;
	string	_nickN;
	string	_phoneN;
	string	_darkS;

};

#endif