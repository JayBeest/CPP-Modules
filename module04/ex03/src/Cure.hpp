#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"
# include "compat.h"

class Cure : public AMateria {

public:

					Cure & operator=( const Cure & rhs);
					Cure( void );
					Cure( const Cure & src );
	virtual			~Cure( void );

	virtual void	use( ICharacter & target) const;
	virtual Cure *	clone( void ) const;

private:

};

#endif
