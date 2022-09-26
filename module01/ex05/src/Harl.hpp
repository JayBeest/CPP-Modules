#ifndef HARL_H
# define HARL_H

# include <iostream>

class Harl {

public:

	void			complain( std::string level );

					Harl( );

private:

	void			debug( void );
	void			info( void );
	void			warning( void );
	void			error( void );
	std::string		_karen_state[4];
	void			( Harl::*_funptr[4] )( void );

};

#endif
