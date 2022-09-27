#ifndef BRAIN_H
# define BRAIN_H

# define MAX_IDEAS 3

# include <iostream>

class Brain {

public:

	std::string			getIdea( unsigned int index ) const;
	long				getIdeaLoc( unsigned int index ) const;
	void				addIdea( const std::string & idea );

	explicit			Brain( const std::string & first_idea );
						Brain( );
						Brain( const Brain & other );
	virtual				~Brain( );
	Brain &				operator=( const Brain & rhs );

	static void			makeSilent( void );

private:

	std::string			_ideas[MAX_IDEAS];
	unsigned int		_idea_id;
	static bool			_loud;

};

std::ostream &			operator<<( std::ostream & o_stream, const Brain & brain );

#endif
