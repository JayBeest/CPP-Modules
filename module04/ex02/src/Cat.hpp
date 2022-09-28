#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

public:

	Brain &			accessBrain( void ) const;

	explicit		Cat( std::string type );
					Cat( );
					Cat( const Cat & other );
	virtual			~Cat( );
	Cat &			operator=( const Cat & rhs );

	virtual void	makeSound( void ) const;

private:

	Brain *			_brain;

};

#endif
