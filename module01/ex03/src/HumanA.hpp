#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA {

public:

    const std::string &	getName( void ) const;

	explicit			HumanA( const std::string & name, Weapon & weapon );
						~HumanA( );

	void				attack( void ) const;

private:

	std::string			_name;
	Weapon &			_weapon;

};

std::ostream &			operator<<( std::ostream & o_stream, const HumanA & human );

#endif
