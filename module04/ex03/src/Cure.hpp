#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria {

public:

					Cure( void );
					Cure( const Cure & other );
	virtual			~Cure( void );
	Cure &			operator=( const Cure & rhs );

	virtual void	use( ICharacter & target ) const;
	virtual Cure *	clone( void ) const;

private:

};

#endif
