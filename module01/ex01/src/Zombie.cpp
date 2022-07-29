#include <sstream>
#include "Zombie.hpp"

///			Public:

std::string ClassZombie::getName( ) const {

	return this->_string;
}

///			Constructor/Destroyer

ClassZombie::ClassZombie( std::string name ) : _string(name) {

	this->_id = ClassZombie::_zombie_counter;
	ClassZombie::_zombie_counter++;

}

ClassZombie::ClassZombie( ) {

	this->_string = "))<>((";

}

ClassZombie::ClassZombie( const ClassZombie& other ) {

	*this = other;
}

ClassZombie::~ClassZombie( ) {

	std::cout << this->getName() << ": (re)died a horrible death.. \"" << "Gnar'har-chuck'" << "gluck!\"" << std::endl;
}

ClassZombie &	ClassZombie::operator=( const ClassZombie& rhs ) {

	if (this != &rhs)
	{
		std::cout << "this != &rhs!!!!!" << std::endl;
		this->_string = rhs.getName();	// TODO
	}
	return *this;
}

///			Functions/Methods

void	ClassZombie::announce( ) const {

	std::stringstream	o_stream;

	o_stream << this->_id;
	std::cout << this->getName() << "_" << o_stream << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

///			Private:


int	ClassZombie::_zombie_counter = 0;