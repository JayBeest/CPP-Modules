#ifndef AMATERIA_H
# define AMATERIA_H

//# include "ICharacter.hpp"

class ICharacter;

class AMateria {

public:

	std::string const &	getType( ) const;

	explicit			AMateria( std::string const & type );

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter & target);

	static void			makeSilent( void );
	static bool			_loud;

protected:

						AMateria( );
						~AMateria( );
						AMateria( const AMateria & src );

private:

						AMateria & operator=( const AMateria & rhs);

	std::string			_type;

};

#endif
