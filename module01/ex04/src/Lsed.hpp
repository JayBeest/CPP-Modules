#ifndef LSED_H
# define LSED_H

# include <iostream>
# include <fstream>

struct Lsed {

	bool			setupLoser( char **argv );
	bool			tryOpen( void );
	bool			readWrite( void );
	void			checkWriteC(char c ) ;
	bool			tryClose( void );


	std::string		s1;
	std::string		s2;
	std::string		file;
	std::fstream	in_file;
	std::fstream	out_file;

					Lsed( );
					Lsed( const Lsed & src );
					~Lsed( );
					Lsed & operator=( const Lsed & rhs);


	std::string		*s1_ptr;
	std::string		*s2_ptr;

};

#endif
