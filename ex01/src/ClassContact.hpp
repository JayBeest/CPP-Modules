#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

using std::string;

class Contact {


public:

	Contact( string f, string l, string n, string p, string d);
	Contact( Contact const & other);
	Contact( void );
	~Contact ( void );

	Contact &	operator=( Contact const & rhs );

	string	getFirstN ( ) const;
	string	getLastN ( ) const;
	string	getNickN ( ) const;
	string	getPhoneN ( ) const;
	string	getDarkS ( ) const;
//	void	print( void ) const;
	int		get_nbContacts ( void ) const;

private:


	static int	_nb_contacts_constructed;

	string	_firstN;
	string	_lastN;
	string	_nickN;
	string	_phoneN;
	string	_darkS;

};

//std::ostream &	operator<<( std::ostream & o, Contact const & rhs );

#endif