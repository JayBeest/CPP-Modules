#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# define MAX_SOURCE_INV 4

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

						MateriaSource( );
	virtual				~MateriaSource( );

protected:

						MateriaSource( const MateriaSource & other );
	MateriaSource &		operator=( const MateriaSource & rhs );

	virtual void		learnMateria( AMateria * materia );
	virtual AMateria *	createMateria( const std::string & type );

	static void			makeSilent( void );

private:

	AMateria *			_source_inventory[MAX_SOURCE_INV];

};

#endif
