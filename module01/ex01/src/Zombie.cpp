#include <sstream>
#include "Zombie.hpp"

///			Public:

std::string Zombie::getName( ) const {

	return this->_name;
}

///			Constructor/Destroyer

Zombie::Zombie( const std::string & name )
	: _id(Zombie::_id_counter), _name(name) {

	Zombie::_id_counter++;
}

Zombie::Zombie( )
	: _id(Zombie::_id_counter), _name("<no_name>") {

	Zombie::_id_counter++;
}

Zombie::~Zombie( ) {

	std::stringstream	o_stream;

	o_stream << this->_id;
	std::cout << this->getName() << "_" << o_stream.str() << ": died (again) a horrible death.. \"" << "Gnar'har-chuck'" << "gluck!\"" << std::endl;
}

Zombie::Zombie( const Zombie & other ) {

    if (this != &other)
    {
        *this = other;
    }
}

Zombie &    Zombie::operator=( const Zombie & rhs ) {

    if (this != &rhs)
    {
        this->_name = rhs.getName();
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
