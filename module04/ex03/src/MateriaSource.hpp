#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# define MAX_SOURCE_INV 4

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	virtual				~MateriaSource( );

protected:
						MateriaSource( );
						MateriaSource( const MateriaSource & src );
						MateriaSource & operator=( const MateriaSource & rhs);

	virtual void		learnMateria( AMateria * materia );
	virtual AMateria *	createMateria( std::string const & type );

	static void			makeSilent( void );

private:

	AMateria *			_source_inventory[MAX_SOURCE_INV];

};

#endif
