#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public:

	Brain &			accessBrain( void ) const;

	explicit		Dog( const std::string & type );
					Dog( );
					Dog( const Dog & other );
	virtual			~Dog( );
	Dog &			operator=( const Dog & rhs );

	virtual void	makeSound( void ) const;

private:

	Brain *			_brain;

};

#endif
