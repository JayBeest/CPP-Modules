#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap,  public FragTrap {

public:

	virtual const std::string &	getName( ) const;

	explicit					DiamondTrap( const std::string & name );
								DiamondTrap( );
								DiamondTrap( const DiamondTrap & other );
	virtual						~DiamondTrap( );
	DiamondTrap &				operator=( const DiamondTrap & rhs);

	void						whoAmI( ) const;

private:

	std::string					_name;

};

#endif
