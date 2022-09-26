#ifndef LSED_H
# define LSED_H

# include <iostream>
# include <fstream>

struct Lsed {

	void			initLoser( char ** argv );
	void			tryOpen( void );
	void			tryReadWrite( void );
	void			tryClose( void );
	void			tryWrite( std::string line ) ;

	std::string		find;
	std::string		replace;
	std::string		file;
	std::fstream	in_file;
	std::fstream	out_file;

};

#endif
