#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

public:

	std::string 	getName( ) const;

	explicit		Zombie( std::string name );
					Zombie( );
					Zombie( Zombie const & src );
					~Zombie( );
					Zombie & operator=( Zombie const & rhs);

	void			announce( ) const;

private:

	std::string		_string;

};

Zombie*		newZombie(std::string name);
Zombie		newChump(std::string name);

#endif

