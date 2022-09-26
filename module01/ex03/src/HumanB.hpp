#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB {

public:

	std::string			getName( ) const;
	void				setWeapon( const Weapon & weapon );

	explicit			HumanB( const std::string & name );
						~HumanB( );

	void				attack( ) const;

private:

	std::string			_name;
	Weapon *			_weapon;

};

std::ostream & operator<<(std::ostream & o_stream, const HumanB & human );

#endif
