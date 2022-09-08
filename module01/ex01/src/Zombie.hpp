#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {

public:

	std::string 	getName( ) const;

    explicit        Zombie( const std::string & name );
                    Zombie( );
					~Zombie( );
                    Zombie( const Zombie & other );
    Zombie &        operator=( const Zombie & rhs );

	void			announce( ) const;

private:

	int				_id;
	std::string		_name;

	static int		_id_counter;

};

Zombie *	zombieHorde( int N, std::string name );

#endif
