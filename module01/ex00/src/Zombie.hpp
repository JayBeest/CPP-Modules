#ifndef ZOMBIE_H
# define ZOMBIE_H

class ClassZombie {

public:

	int			getId( ) const;
	int			getVars( ) const;
	int			getNb_ClassZombie_created( ) const;

				ClassZombie( int arg );
				ClassZombie( );
				ClassZombie( const ClassZombie & src );
				~ClassZombie( );
				ClassZombie & operator=( const ClassZombie & rhs);

	void		doStuff() const;

private:

	int			_id;
	int			_vars;
	static int	_nb_ClassZombie_created;

};

#endif
