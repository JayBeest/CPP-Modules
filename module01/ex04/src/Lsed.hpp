#ifndef LSED_H
# define LSED_H

class Lsed {

public:

	std::string		s1;
	std::string		s2;

					Lsed( );
					Lsed( const Lsed & src );
					~Lsed( );
					Lsed & operator=( const Lsed & rhs);

	void			processC( char c ) ;

private:

	std::string		*_s1;
	std::string		*_s2;

};

#endif
