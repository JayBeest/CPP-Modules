#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <iostream>

class WrongAnimal {

public:

	std::string		getType( ) const;

	explicit		WrongAnimal( std::string type );
					WrongAnimal( );
					WrongAnimal( const WrongAnimal & src );
	virtual			~WrongAnimal( );
					WrongAnimal & operator=( const WrongAnimal & rhs);

	void			makeSound( void ) const;
	static void		makeSilent( void );

protected:


	std::string		type;
	static bool		_loud;

private:

};

std::ostream & operator<<( std::ostream & o_stream, const WrongAnimal & animal);

#endif
