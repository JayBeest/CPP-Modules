#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

public:

	std::string 	getName( ) const;

	explicit		Zombie(std::string name );
					Zombie( );
					Zombie(const Zombie & src );
					~Zombie( );
					Zombie & operator=(const Zombie & rhs);

	void			announce( ) const;

private:

	int				_id;
	std::string		_string;

	static int		_zombie_counter;

};

Zombie*	zombieHorde(int N, std::string name);

#endif

