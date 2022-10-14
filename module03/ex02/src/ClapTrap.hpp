#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {

public:

	const std::string & getName( ) const;
	unsigned int	    getHitPoints( ) const;
	unsigned int	    getEnergyPoints( ) const;
	unsigned int	    getAttackDamage( ) const;
	void			    setAttackDamage( unsigned int damage );

	explicit		    ClapTrap( const std::string & name );
					    ClapTrap( );
					    ClapTrap( const ClapTrap & other );
					    ~ClapTrap( );
	ClapTrap &          operator=( const ClapTrap & rhs );

	virtual void	    attack( const std::string & target );
	void			    takeDamage( unsigned int amount );
	void			    beRepaired( unsigned int amount );

	static void		    makeSilent( );

protected:

	std::string		    _name;
	unsigned int	    _hitPoints;
	unsigned int	    _energyPoints;
	unsigned int	    _attackDamage;

	static bool			_loud;

};

#endif
