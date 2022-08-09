#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {

public:

	std::string		getName( void ) const;
	unsigned int	getHitPoints( void ) const;
	unsigned int	getEnergyPoints( void ) const;
	unsigned int	getAttackDamage( void ) const;
	void			setAttackDamage( unsigned int damage );

	explicit		ClapTrap( const std::string & name );
					ClapTrap( );
					ClapTrap( const ClapTrap & src );
					~ClapTrap( );
					ClapTrap & operator=( const ClapTrap & rhs);

	void			attack( const std::string & target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	static void		makeSilent( void );

private:

	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

	static bool		_loud;

};

#endif
