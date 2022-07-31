#include <iostream>
#include "Lsed.hpp"

///			Public:

///			Constructor/Destroyer

Lsed::Lsed(	) : _s1(nullptr) {

										// TODO not counting default constructor

}

Lsed::Lsed( Lsed const & other) : _s1(nullptr), _s2(nullptr) {

	if (this != &other)
	{
		if (other._s1)
			this->_s1 = new std::string();
		else
			this->_s1 = nullptr;
		if (other._s2)
			this->_s2 = new std::string();
		else
			this->_s2 = nullptr;
		// TODO
	}
}

Lsed::~Lsed( ) {

	delete _s1;
	// TODO

}

Lsed &	Lsed::operator=( Lsed const & rhs ) {

	delete this->_s1;
	delete this->_s2;
	if (this != &rhs)
	{
		if (rhs._s1)
			this->_s1 = new std::string();
		else
			this->_s1 = nullptr;
		if (rhs._s2)
			this->_s2 = new std::string();
		else
			this->_s2 = nullptr;
		// TODO
	}
	return *this;
}

///			Functions/Methods

void	Lsed::processC( char c ) {

	static size_t size = 0;

	if (c == this->s1.c_str()[size])
	{
		size++;
		if (size == this->s1.length())
		{
			std::cout << s2;
			size = 0;
		}
	}
	else if (size > 0)
	{
		std::cout << this->s1.substr(0, size) << c;
		size = 0;
	}
	else
		std::cout << c;

}

///			Private:

