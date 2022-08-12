#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria {

public:

	int				getVars( ) const;

	explicit		Ice( int arg );
					Ice( );
					Ice( const Ice & src );
	virtual			~Ice( );
					Ice & operator=( const Ice & rhs);

	virtual AMateria *	clone( void ) const;

private:

	int				_vars;

};

#endif
