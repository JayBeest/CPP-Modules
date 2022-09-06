#ifndef HARL_H
# define HARL_H

# include <iostream>

typedef enum e_pain_lvl
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	OBNOXIOUS
}		t_pain_lvl;

class Harl {

public:

	void			complain( std::string level );

					Harl( );

private:

	void			debug( void );
	void			info( void );
	void			warning( void );
	void			error( void );
	void			obnox( void );
	std::string		_karen_state[4];
	void			(Harl::*_funptr[5])(void);

};

#endif
