#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>

class AAnimal {

public:

	std::string		getType( ) const;

	virtual			~AAnimal( );

	virtual void	makeSound( void ) const = 0;
	static void		makeSilent( void );

protected:

	explicit		AAnimal( std::string type );
					AAnimal( );
					AAnimal( const AAnimal & other );
	AAnimal &		operator=( const AAnimal & rhs );

	std::string		type;
	static bool		_loud;

private:

};

std::ostream & operator<<( std::ostream & o_stream, const AAnimal & animal);

#endif
