#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	explicit		ScavTrap( const std::string & name );
					ScavTrap( );
					ScavTrap( const ScavTrap & other );
					~ScavTrap( );
	ScavTrap &      operator=( const ScavTrap & rhs );

	virtual void	attack( const std::string & target );
	void			guardGate( );

private:

};

#endif
