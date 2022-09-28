#ifndef FIRE_H
# define FIRE_H

# include "AMateria.hpp"

class Fire : public AMateria {

public:

					Fire( void );
					Fire( const Fire & other );
	virtual			~Fire( void );
	Fire &			operator=( const Fire & rhs );

	virtual void	use( ICharacter & target ) const;
	virtual Fire *	clone( void ) const;

private:

};

#endif
