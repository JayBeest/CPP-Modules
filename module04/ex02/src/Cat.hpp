#ifndef CAT_H
# define CAT_H

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

public:

	Brain &			accessBrain( void ) const;

	explicit		Cat( std::string type );
					Cat( );
					Cat( const Cat & src );
	virtual			~Cat( );
					Cat & operator=( const Cat & rhs);

	virtual void	makeSound( void ) const;
	static void		makeSilent( void );

private:

	Brain *			_brain;

};

#endif