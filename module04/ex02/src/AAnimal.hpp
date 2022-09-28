#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <fstream>

class Animal {

public:

	std::string		getType( ) const;

	virtual			~Animal( );

	virtual void	makeSound( void ) const = 0;
	static void		makeSilent( void );

protected:

	explicit		Animal( std::string type );
					Animal( );
					Animal( const Animal & src );
					Animal & operator=( const Animal & rhs);

	std::string		type;
	static bool		_loud;

private:

};

std::ostream & operator<<( std::ostream & o_stream, const Animal & animal);

#endif
