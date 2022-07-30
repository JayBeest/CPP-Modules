#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class ClassZombie {

public:

	std::string 	getName( ) const;

	explicit		ClassZombie( std::string name );
					ClassZombie( );
					ClassZombie( ClassZombie const & src );
					~ClassZombie( );
					ClassZombie & operator=( ClassZombie const & rhs);

	void			announce( ) const;

private:

	std::string		_string;

};

ClassZombie*	newZombie(std::string name);
ClassZombie		newChump(std::string name);

#endif

