#include <iostream>
#include "Sample.class.hpp"

Sample1::Sample1( float const f ) : pi(f), qd(42) {

	std::cout << "Constructor called" << std::endl;

	this->bar();

	return;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample1::bar( void ) const{

	std::cout << "this->pi: " << this->pi << std::endl;
	std::cout << "this->qd: " << this->qd << std::endl;

	this->qd = 0;

	return;
}