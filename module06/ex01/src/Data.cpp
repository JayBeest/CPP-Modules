#include "Data.hpp"

///			Public:

///			Getters / Setters

int		Data::getData( ) const {

	return this->_data;
}

void	Data::setData( const int & data ) {

	this->_data = data;
}

///			Constructor / Destructor

Data::Data( ) : _data(0) {

}

Data::Data( const Data & other ) {

	if (this != &other)
	{
	  *this = other;
	}
}

Data::~Data( ) {

}

Data &	Data::operator=( const Data & rhs ) {

	if (this != &rhs)
	{
		this->_data = rhs.getData();
	}
	return *this;
}

///			Functions / Methods

///			Private:

