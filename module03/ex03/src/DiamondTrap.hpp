#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap,  public FragTrap {

public:

	virtual std::string		getName( void ) const;

	explicit				DiamondTrap( const std::string & name );
							DiamondTrap( );
							DiamondTrap( const DiamondTrap & src );
	virtual					~DiamondTrap( );
							DiamondTrap & operator=( const DiamondTrap & rhs);

	void					whoAmI( void ) const;

private:

	std::string				_name;

};

#endif
