#include <sstream>
#include "Zombie.hpp"

///			Public:

std::string Zombie::getName( ) const {

	return this->_string;
}

///			Constructor/Destroyer

Zombie::Zombie(std::string name ) : _string(name) {

	this->_id = Zombie::_zombie_counter;
	Zombie::_zombie_counter++;

}

Zombie::Zombie( ) {

	this->_id = Zombie::_zombie_counter;
	Zombie::_zombie_counter++;

}

Zombie::Zombie(const Zombie& other ) {

	*this = other;
}

Zombie::~Zombie( ) {

	std::stringstream	o_stream;

	o_stream << this->_id;
	std::cout << this->getName() << "_" << o_stream.str() << ": (re)died a horrible death.. \"" << "Gnar'har-chuck'" << "gluck!\"" << std::endl;
}

Zombie &	Zombie::operator=(const Zombie& rhs ) {

	if (this != &rhs)
	{
		this->_string = rhs.getName();	// TODO
	}
	return *this;
}

///			Functions/Methods

void	Zombie::announce( ) const {

	std::stringstream	o_stream;

	o_stream << this->_id;
	std::cout << this->getName() << "_" << o_stream.str() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

///			Private:


int	Zombie::_zombie_counter = 0;