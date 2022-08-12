#ifndef FIRE_H
# define FIRE_H

# include "AMateria.hpp"
# include "compat.h"

class Fire : public AMateria {

public:

					Fire & operator=( const Fire & rhs);
					Fire( void );
					Fire( const Fire & src );
	virtual			~Fire( void );

	virtual void	use( ICharacter & target) const;
	virtual Fire *	clone( void ) const;

private:

};

#endif
