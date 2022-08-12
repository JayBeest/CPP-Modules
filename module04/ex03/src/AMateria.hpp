#ifndef AMATERIA_H
# define AMATERIA_H

//# include "ICharacter.hpp"

class ICharacter;

class AMateria {

public:

	std::string const &	getType( ) const;

	explicit			AMateria( std::string const & type );
	virtual				~AMateria( void );

	virtual void		use( ICharacter & target ) const;
	virtual AMateria *	clone( void ) const = 0;

	static void			makeSilent( void );
	static bool			_loud;

protected:

						AMateria( );
						AMateria( const AMateria & src );

private:

						AMateria & operator=( const AMateria & rhs );

	std::string			_type;

};

std::ostream & operator<<( std::ostream & o_stream, const AMateria & materia );

#endif
