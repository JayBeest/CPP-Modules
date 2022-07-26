#ifndef WRONG_CAT_H
# define WRONG_CAT_H

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	explicit		WrongCat( std::string type );
					WrongCat( );
					WrongCat( const WrongCat & other );
	virtual			~WrongCat( );
	WrongCat &		operator=( const WrongCat & rhs );

	void			makeSound( void ) const;
	static void		makeSilent( void );

private:

};

#endif
