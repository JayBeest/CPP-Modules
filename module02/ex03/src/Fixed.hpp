#ifndef FIXED_H
# define FIXED_H

class Fixed {

public:

	int				getRawBits( ) const;
	void			setRawBits( const int raw );
	static void		makeSilent( void );

					Fixed( );
					Fixed( const int int_value );
					Fixed( const float float_value );
					Fixed( const Fixed & src );
					~Fixed( );
					Fixed & operator=( const Fixed & rhs);

	bool			operator>( const Fixed & rhs) const;
	bool			operator>=( const Fixed & rhs) const;
	bool			operator<( const Fixed & rhs) const;
	bool			operator<=( const Fixed & rhs) const;
	bool			operator==( const Fixed & rhs) const;
	bool			operator!=( const Fixed & rhs) const;

					Fixed  operator+( const Fixed & rhs) const;
					Fixed  operator-( const Fixed & rhs) const;
					Fixed  operator*( const Fixed & rhs) const;
					Fixed  operator/( const Fixed & rhs) const;

					const Fixed operator++( void );
					const Fixed operator++( int );
					const Fixed operator--( void );
					const Fixed operator--( int );

	float			toFloat( void ) const;
	int				toInt( void ) const;

	static Fixed &			min( Fixed & a, Fixed & b );
	static Fixed const &	min( Fixed const & a, Fixed const & b );
	static Fixed &			max( Fixed & a, Fixed & b );
	static Fixed const &	max( Fixed const & a, Fixed const & b );


private:

	int					_fixed_point;
	static int const	_fractional_bits;
	static bool			_loud;

};

std::ostream & operator<<(std::ostream & o_stream, Fixed const & fix);

#endif
