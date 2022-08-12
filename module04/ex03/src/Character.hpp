#ifndef CHARACTER_H
# define CHARACTER_H

# define MAX_INVENTORY 4

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {

public:

	explicit			Character( const std::string & name );
	AMateria *			getInventory( unsigned int index ) const;

protected:

	const std::string &	getName( void ) const;

						Character( const Character & src );
						Character( );
						~Character( );
						Character & operator=( const Character & rhs);

	void				equip( AMateria * m );
	void				unequip( int idx );
	void				use( int idx, ICharacter& target );

	static void			makeSilent( void );

private:

	std::string			_name;
	AMateria *			_inventory[MAX_INVENTORY];
	static bool			_loud;

};

#endif
