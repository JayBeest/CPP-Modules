#include "Zombie.hpp"

///			Public:

std::string Zombie::getName( ) const {

	return this->_name;
}

///			Constructor/Destroyer

Zombie::Zombie( const std::string & name ) : _name(name) {

}

Zombie::~Zombie( ) {

	std::cout << this->getName() << ": died(again) a horrible death.. \"" << "Gnar'har-chuck'" << "gluck!\"" << std::endl;

}

///			Functions/Methods

void	Zombie::announce( ) const {

	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

///			Private:
