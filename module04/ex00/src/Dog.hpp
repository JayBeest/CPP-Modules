#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal {

public:

	explicit		Dog( const std::string & type );
					Dog( );
					Dog( const Dog & other );
	virtual			~Dog( );
	Dog &			operator=( const Dog & rhs );

	virtual void	makeSound( void ) const;
	static void		makeSilent( void );

private:

};

#endif
