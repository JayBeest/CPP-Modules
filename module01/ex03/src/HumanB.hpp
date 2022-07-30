#ifndef HUMANB_H
# define HUMANB_H

class HumanB {

public:

	int				getId( ) const;
	int				getVars( ) const;
	static int		getNb_HumanB_created( );

	explicit		HumanB( int arg );
					HumanB( );
					HumanB( const HumanB & src );
					~HumanB( );
					HumanB & operator=( const HumanB & rhs);

	void			doStuff() const;

private:

	int				_id;
	int				_vars;
	static int		_nb_HumanB_created;

};

#endif
