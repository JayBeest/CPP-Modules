#ifndef HUMANB_H
# define HUMANB_H
# ifndef nullptr
#  define nullptr ((void*)0)
# endif

# include <iostream>
# include <sstream>
# include "Weapon.hpp"

class HumanB {

public:

	std::string			getName( ) const;
	void				setWeapon( const Weapon & weapon );

	std::string			name;
	Weapon *			weapon;

	explicit			HumanB( std::string name );
						HumanB( );
						~HumanB( );
						HumanB( const HumanB & src );
						HumanB & operator=( const HumanB & rhs);

	void				attack( ) const;

private:

	static int			_nb_humanAs_alive;

};

std::ostream &operator<<(std::ostream& o_stream, HumanB & rhs);

#endif
