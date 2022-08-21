#ifndef LSED_H
# define LSED_H

# include <iostream>
# include <fstream>

struct Lsed {

	void			initLoser(char **argv );
	bool			tryOpen( void );
	bool			tryReadWrite(void );
	bool			tryClose( void );
	void			tryWrite(char c ) ;

	std::string		s1;
	std::string		s2;
	std::string		file;
	std::fstream	in_file;
	std::fstream	out_file;

};

#endif
