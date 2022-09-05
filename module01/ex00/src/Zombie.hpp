#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {

public:

	std::string 	getName( ) const;

	explicit		Zombie( const std::string & name );
					Zombie( );
                    Zombie( Zombie const & other );
					~Zombie( );
					Zombie & operator=( Zombie const & rhs );

	void			announce( ) const;

private:

	std::string		_string;

};

Zombie*		newZombie(std::string name);
void		newChump(std::string name);

#endif

