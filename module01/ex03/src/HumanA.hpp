#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include "Weapon.hpp"

class HumanA {

public:

	std::string			name;
	Weapon &			weapon;

	explicit			HumanA( std::string const & name, Weapon & weapon );
						HumanA( );
						~HumanA( );
						HumanA( HumanA const & src );
						HumanA & operator=( HumanA const & rhs );

	void				attack( ) const;

private:

	static int			_nb_humanAs_alive;
	static Weapon *		_default_weapon;

};

#endif
