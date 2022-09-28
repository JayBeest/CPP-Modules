#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria {

public:

					Ice( void );
					Ice( const Ice & other );
	virtual			~Ice( void );
	Ice &			operator=( const Ice & rhs );

	virtual void	use( ICharacter & target ) const;
	virtual Ice *	clone( void ) const;

private:

};

#endif
