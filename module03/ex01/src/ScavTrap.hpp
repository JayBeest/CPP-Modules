#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	explicit		ScavTrap( const std::string & name );
					ScavTrap( );
					ScavTrap( const ScavTrap & src );
					~ScavTrap( );
					ScavTrap & operator=( const ScavTrap & rhs);

	void			attack( const std::string & target );
	void			guardGate( );

private:

};

#endif
