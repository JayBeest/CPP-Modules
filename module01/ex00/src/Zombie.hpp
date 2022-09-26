#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {

public:

	std::string 	getName( ) const;

	explicit		Zombie( const std::string & name );
					~Zombie( );

	void			announce( ) const;

private:

	std::string		_name;

};

Zombie *			newZombie( std::string name );
void				randomChump( std::string name );

#endif

