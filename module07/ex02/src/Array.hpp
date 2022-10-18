#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template<typename T>
class Array {

public:

					Array<T>( );
					Array<T>( unsigned int const & n );
					Array<T>( Array<T> const & other );
					~Array( );
	Array<T> &		operator=( Array<T> const & rhs );
	T &				operator[]( int index );

	int				size( ) const;
	unsigned int	_size;
	T *				_array;

private:


};

template<typename T>
std::ostream &	operator<<( std::ostream & o_stream, Array<T> const & array );

#endif
