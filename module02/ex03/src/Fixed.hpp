#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

public:

	int						getRawBits( void ) const;
	void					setRawBits( const int & raw );
	static void				makeSilent( void );

							Fixed( );
	explicit				Fixed( const int & int_value );
	explicit				Fixed( const float & float_value );
							Fixed( const Fixed & other );
							~Fixed( );
	Fixed &					operator=( const Fixed & rhs );

	bool					operator>( const Fixed & rhs ) const;
	bool					operator>=( const Fixed & rhs ) const;
	bool					operator<( const Fixed & rhs ) const;
	bool					operator<=( const Fixed & rhs ) const;
	bool					operator==( const Fixed & rhs ) const;
	bool					operator!=( const Fixed & rhs ) const;

    Fixed           		operator+( const Fixed & rhs ) const;
    Fixed           		operator-( const Fixed & rhs ) const;
    Fixed           		operator*( const Fixed & rhs ) const;
    Fixed           		operator/( const Fixed & rhs ) const;

    Fixed           		operator++( void );
    Fixed           		operator++( int );
    Fixed           		operator--( void );
    Fixed           		operator--( int );

	float					toFloat( void ) const;
	int 					toInt( void ) const;

	static Fixed &			min( Fixed & a, Fixed & b );
	static const Fixed &	min( const Fixed & a, const Fixed & b );
	static Fixed &			max( Fixed & a, Fixed & b );
	static const Fixed &	max( const Fixed & a, const Fixed & b );


private:

	int						_fixed_point;
	static int const		_fractional_bits;
	static bool				_loud;

};

std::ostream &	operator<<( std::ostream & o_stream, const Fixed & fix );

#endif
