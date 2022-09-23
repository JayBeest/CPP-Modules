#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <iostream>

class WrongAnimal {

public:

	std::string		getType( ) const;

	explicit		WrongAnimal( const std::string & type );
					WrongAnimal( );
					WrongAnimal( const WrongAnimal & other );
	virtual			~WrongAnimal( );
	WrongAnimal &	operator=( const WrongAnimal & rhs );

	void			makeSound( void ) const;
	static void		makeSilent( void );

protected:


	std::string		type;
	static bool		_loud;

private:

};

#endif
