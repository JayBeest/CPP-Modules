#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap( T & lhs, T & rhs ) {

	T	temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template<typename T>
const T &	min( T const & lhs, T const & rhs ) {

	return (lhs < rhs ? lhs : rhs);
}

template<typename T>
const T &	max( T const & lhs, T const & rhs ) {

	return (lhs > rhs ? lhs : rhs);
}

#endif
