#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include "compat.h"

class Ice : public AMateria {

public:

					Ice & operator=( const Ice & rhs);
					Ice( void );
					Ice( const Ice & src );
	virtual			~Ice( void );

	virtual void	use( ICharacter & target ) const;
	virtual Ice *	clone( void ) const;

private:

};

#endif
