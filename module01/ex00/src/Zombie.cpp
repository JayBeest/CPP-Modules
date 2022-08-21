#include "Zombie.hpp"

///			Public:

std::string Zombie::getName( ) const {

	return this->_string;
}

///			Constructor/Destroyer

Zombie::Zombie( std::string name ) : _string(name) {

	this->announce();
}

Zombie::Zombie(	) : _string("<no_name>") {

}

Zombie::Zombie( Zombie const & other) {

	if (this != &other)
	{
		*this = other;
	}
}

Zombie::~Zombie( ) {

	std::cout << this->getName() << ": (re)died a horrible death.. \"" << "Gnar'har-chuck'" << "gluck!\"" << std::endl;

}

Zombie &	Zombie::operator=( Zombie const & rhs ) {

	if (this != &rhs)
	{
		this->_string = rhs.getName();
	}
	return *this;
}

///			Functions/Methods

void	Zombie::announce( ) const {

	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

///			Private:
