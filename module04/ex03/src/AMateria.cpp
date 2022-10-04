#include "AMateria.hpp"
#include "ICharacter.hpp"

///			Public:

///			Getters / Setters


std::string const &	AMateria::getType( ) const {

	return this->_type;
}

///			Constructor / Destructor

AMateria::AMateria( const std::string & type ) : _type(type) {

	if (AMateria::_loud)
  		std::cout << "[AMateria] Specific constructor called" << std::endl;
}

AMateria::AMateria( ) {

	if (AMateria::_loud)
  		std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria( const AMateria & other ) {

	if (this != &other)
	{
	  *this = other;
	}
	if (AMateria::_loud)
  		std::cout << "[AMateria] Copy constructor called" << std::endl;
}

AMateria::~AMateria( ) {

	if (AMateria::_loud)
  		std::cout << "[AMateria] Destructor called" << std::endl;
}

AMateria &	AMateria::operator=( const AMateria & rhs ) {

	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	if (AMateria::_loud)
  		std::cout << "[AMateria] Copy assignment operator called" << std::endl;
	return *this;
}

///			Functions / Methods

void	AMateria::use( ICharacter & target ) const {

		std::cout << "AMateria:use -- This should never show up..(" << target.getName() << ")" << std::endl;
}

void	AMateria::makeSilent( void ) {

	AMateria::_loud = false;
}

///			Private:

bool	AMateria::_loud = true;

std::ostream &	operator<<( std:: ostream & o_stream, const AMateria & materia ) {

	return o_stream << materia.getType();
}
