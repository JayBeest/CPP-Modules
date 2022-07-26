#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact {

public:

	static int			get_nbContacts( );
	std::string			getFirstN( ) const;
	std::string			getLastN( ) const;
	std::string			getNickN( ) const;
	std::string			getPhoneN( ) const;
	std::string			getDarkS( ) const;

	Contact( );
	Contact( const Contact& other );
	Contact( const std::string & f, const std::string & l, const std::string & n, const std::string & p, const std::string & d );
	~Contact ( );

	Contact&	operator=( const Contact& rhs );


private:

	static int	_nb_contacts;

	std::string	_firstN;
	std::string	_lastN;
	std::string	_nickN;
	std::string	_phoneN;
	std::string	_darkS;

};

#endif
