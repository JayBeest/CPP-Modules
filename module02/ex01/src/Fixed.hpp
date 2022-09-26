#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

public:

	int				    getRawBits( ) const;
	void			    setRawBits( const int & raw );

					    Fixed( );
					    Fixed( const int & int_value );
					    Fixed( const float & float_value );
					    Fixed( const Fixed & other );
					    ~Fixed( );
	Fixed &				operator=( const Fixed & rhs );

	float			    toFloat( void ) const;
	int				    toInt( void ) const;

private:

	int					_fixed_point;
	static int const	_fractional_bits;

};

std::ostream &			operator<<( std::ostream & o_stream, const Fixed & fix );

#endif
