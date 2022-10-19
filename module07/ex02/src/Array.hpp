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
	T &				operator[]( size_t index ) const;

	int				size( ) const;
	size_t			_size;
	T *				_array;

private:


};

template<typename T>
std::ostream &	operator<<( std::ostream & o_stream, Array<T> const & array );

#endif
