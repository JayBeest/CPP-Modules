#ifndef CHARACTER_H
# define CHARACTER_H

# define MAX_INVENTORY 4
# define MAX_GROUND 100

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {

public:

	explicit			Character( const std::string & name );
	static void			makeSilent( void );

protected:

	const std::string &	getName( void ) const;

						Character( const Character & other );
						Character( );
						~Character( );
	Character &			operator=( const Character & rhs);

	virtual void		equip( AMateria * m );
	virtual void		unEquip( int idx );
	virtual void		use( int idx, ICharacter & target );
	virtual AMateria *	getInventory( unsigned int index ) const;

private:

	void				dropToGround( AMateria * materia );

	std::string			_name;
	AMateria *			_inventory[MAX_INVENTORY];
	AMateria *			_ground[MAX_GROUND];

	static bool			_loud;

};

#endif
