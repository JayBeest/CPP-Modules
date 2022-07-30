#include <sstream>
#include "Zombie.hpp"

///			Public:

std::string Zombie::getName( ) const {

	return this->_string;
}

///			Constructor/Destroyer

Zombie::Zombie( std::string name ) : _string(name) {

	this->_id = Zombie::_id_counter;
	Zombie::_id_counter++;

}

Zombie::Zombie( ) {

	this->_id = Zombie::_id_counter;
	Zombie::_id_counter++;

}

Zombie::Zombie( Zombie const & other ) {

	*this = other;
}

Zombie::~Zombie( ) {

	std::stringstream	o_stream;

	o_stream << this->_id;
	std::cout << this->getName() << "_" << o_stream.str() << ": (re)died a horrible death.. \"" << "Gnar'har-chuck'" << "gluck!\"" << std::endl;
}

Zombie &	Zombie::operator=( Zombie const & rhs ) {

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


int	Zombie::_id_counter = 0;