#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:

	explicit		FragTrap( const std::string & name );
					FragTrap( );
					FragTrap( const FragTrap & src );
	virtual			~FragTrap( );
					FragTrap & operator=( const FragTrap & rhs);

	void			highFivesGuys( void );

private:

};

#endif
