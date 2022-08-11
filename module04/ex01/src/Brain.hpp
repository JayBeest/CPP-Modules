#ifndef BRAIN_H
# define BRAIN_H

# define MAX_IDEAS 100

# include <iostream>

class Brain {

public:

	std::string		getIdea( unsigned int index ) const;

	explicit		Brain( const std::string & first_idea );
					Brain( );
					Brain( const Brain & src );
	virtual			~Brain( );
					Brain & operator=( const Brain & rhs);

	static void		makeSilent( void );

private:

	std::string		ideas[MAX_IDEAS];
	static bool		_loud;

};

#endif
