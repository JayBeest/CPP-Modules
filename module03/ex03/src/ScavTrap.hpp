#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:

	explicit		ScavTrap( const std::string & name );
					ScavTrap( );
					ScavTrap( const ScavTrap & other );
	virtual			~ScavTrap( );
	ScavTrap &		operator=( const ScavTrap & rhs );

	virtual void	attack( const std::string & target );
	void			guardGate( );

private:

};

#endif
