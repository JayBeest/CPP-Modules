#include "ICharacter.hpp"
#include "AMateria.hpp"

ICharacter::~ICharacter( ) {
	if (AMateria::_loud)
		std::cout << "[ICharacter] Destructor called" << std::endl;
}
