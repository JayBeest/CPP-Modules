#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal {

public:

	const std::string &	getType( ) const;

	explicit			Animal( const std::string & type );
						Animal( );
						Animal( const Animal & other );
	virtual				~Animal( );
	Animal &			operator=( const Animal & rhs );

	virtual void		makeSound( void ) const;
	static void			makeSilent( void );

protected:

	std::string			type;
	static bool			_loud;

private:

};

std::ostream &	operator<<( std::ostream & o_stream, const Animal & animal );

#endif
