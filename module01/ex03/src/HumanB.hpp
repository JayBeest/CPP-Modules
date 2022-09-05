#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include <sstream>

# include "nullptr_compat.h"
# include "Weapon.hpp"

class HumanB {

public:

	static bool			verbose;

	std::string			getName( ) const;
	void				setWeapon( Weapon const & weapon );


	explicit			HumanB( std::string const & name );
						~HumanB( );
						HumanB( HumanB const & src );
						HumanB & operator=( HumanB const & rhs);

	void				attack( ) const;

private:

	std::string			_name;
	Weapon *			_weapon;

	static int			_nb_humanAs_alive;

};

std::ostream & operator<<(std::ostream & o_stream, HumanB const & human);

#endif
