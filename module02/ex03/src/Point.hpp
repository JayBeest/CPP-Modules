#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {

public:

	const Fixed &	getX( void ) const;
	const Fixed &	getY( void ) const;

					Point( const float & x, const float & y );
					Point( );
					Point( const Point & other );
					~Point( );
					Point & operator=( const Point & rhs);

	bool			operator==( const Point & rhs ) const;

	static void		makeSilent( void );

private:

	const Fixed		x;
	const Fixed		y;

	static bool		_loud;

};

#endif
