#include "Zombie.hpp"

///			Public:

std::string ClassZombie::getName( ) const {

	return this->_string;
}

///			Constructor/Destroyer

ClassZombie::ClassZombie( std::string name ) : _string(name) {

	this->announce();
}

ClassZombie::ClassZombie(	) {

										// TODO not counting default constructor

}

ClassZombie::ClassZombie( ClassZombie const & other) {

	if (this != &other)
	{
		this->_string = other.getName();	// TODO
	}
	*this = other;
}

ClassZombie::~ClassZombie( ) {

	std::cout << this->getName() << ": (re)died a horrible death.. \"" << "Gnar'har-chuck'" << "gluck!\"" << std::endl;

}

ClassZombie &	ClassZombie::operator=( ClassZombie const & rhs ) {

	if (this != &rhs)
	{
		this->_string = rhs.getName();	// TODO
	}
	return *this;
}

///			Functions/Methods

void	ClassZombie::announce( ) const {

	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

///			Private:

