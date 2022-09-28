#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

public:

	Brain &			accessBrain( void ) const;

	explicit		Dog( std::string type );
					Dog( );
					Dog( const Dog & other );
	virtual			~Dog( );
	Dog &			operator=( const Dog & rhs );

	virtual void	makeSound( void ) const;

private:

	Brain *			_brain;

};

#endif
