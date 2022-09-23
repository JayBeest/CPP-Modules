#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat : public Animal {

public:

	explicit		Cat( const std::string & type );
					Cat( );
					Cat( const Cat & other );
	virtual			~Cat( );
	Cat &			operator=( const Cat & rhs );

	virtual void	makeSound( void ) const;
	static void		makeSilent( void );

private:

};

#endif
