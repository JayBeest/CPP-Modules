#ifndef CAT_H
# define CAT_H

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {

public:

	explicit		Cat( std::string type );
					Cat( );
					Cat( const Cat & src );
	virtual			~Cat( );
					Cat & operator=( const Cat & rhs);

	virtual void	makeSound( void ) const;
	static void		makeSilent( void );

private:

};

#endif
