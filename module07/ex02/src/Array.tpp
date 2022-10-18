#include "Array.hpp"

template<typename T>
Array<T>::Array( )
: _size(0), _array(0) {

}

template<typename T>
Array<T>::Array( unsigned int const & n )
:_size(n), _array( new T [n] ) {

}

template<typename T>
Array<T>::Array( Array<T> const & other ) {

	if (this != &other)
	{
		*this = other;
	}
}

template<typename T>
Array<T>::~Array( ) {


}

template<typename T>
Array<T> &	Array<T>::operator=( Array<T> const & rhs ) {

	if (this != &rhs)
	{
		//copy array;
	}
	return *this;
}

template<typename T>
T &		Array<T>::operator[]( int index ) {

	return _array[index];
}

template<typename T>
int	Array<T>::size( ) const {

	return _size;
}

template<typename T>
std::ostream &	operator<<( std::ostream & o_stream, Array<T> const & array ) {


	return o_stream << array._array;
}
