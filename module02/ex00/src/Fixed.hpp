#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

public:

	int				getRawBits( ) const;
	void			setRawBits( const int & raw );

					Fixed( );
					Fixed( const Fixed & other );
					~Fixed( );
	Fixed &			operator=( const Fixed & rhs );

private:

	int					_fixed_point;
	static int const	_fractional_bits;

};

#endif
