#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

public:

	std::string 	getName( ) const;

	explicit		Zombie(std::string name );
					Zombie( );
					Zombie( Zombie const & src );
					~Zombie( );
					Zombie & operator=( Zombie const & rhs);

	void			announce( ) const;

private:

	int				_id;
	std::string		_string;

	static int		_id_counter;

};

Zombie *	zombieHorde(int N, std::string name);

#endif

