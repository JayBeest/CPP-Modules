#ifndef DOG_H
# define DOG_H

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public:

	Brain &			accessBrain( void ) const;

	explicit		Dog( std::string type );
					Dog( );
					Dog( const Dog & src );
	virtual			~Dog( );
					Dog & operator=( const Dog & rhs);

	virtual void	makeSound( void ) const;
	static void		makeSilent( void );

private:

	Brain *			_brain;

};

#endif