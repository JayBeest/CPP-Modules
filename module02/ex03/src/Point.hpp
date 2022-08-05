#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {

public:

	const Fixed &	getX( ) const;
	const Fixed &	getY( ) const;

					Point( const float x, const float y );
					Point( );
					Point( const Point & src );
					~Point( );
					Point & operator=( const Point & rhs);

	void			doStuff() const;

private:

	const Fixed		x;
	const Fixed		y;

};

#endif
