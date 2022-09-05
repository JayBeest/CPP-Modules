#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include "Weapon.hpp"

class HumanA {

public:

	static bool			verbose;
    const std::string & getName( void ) const;

	explicit			HumanA( std::string const & name, Weapon & weapon );
						~HumanA( );

	void				attack( void ) const;

private:

	std::string			_name;
	Weapon &			_weapon;
	static int			_nb_humanAs_alive;

};

std::ostream &	operator<<(std::ostream & o_stream, HumanA const & human);

#endif
