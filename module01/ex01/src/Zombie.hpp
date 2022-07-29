#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class ClassZombie {

public:

	std::string 	getName( ) const;

	explicit		ClassZombie( std::string name );
					ClassZombie( );
					ClassZombie( const ClassZombie & src );
					~ClassZombie( );
					ClassZombie & operator=( const ClassZombie & rhs);

	void			announce( ) const;

private:

	int				_id;
	std::string		_string;

	static int		_zombie_counter;

};

ClassZombie*	zombieHorde(int N, std::string name);

#endif

