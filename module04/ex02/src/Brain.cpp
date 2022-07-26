#include "Brain.hpp"

///			Public:

///			Getters / Setters

std::string	Brain::getIdea( unsigned int index ) const {

	if (index >= MAX_IDEAS)
	{
		return "index out of range!";
	}
	return this->_ideas[index];
}

long	Brain::getIdeaLoc( unsigned int index ) const {

	if (index >= MAX_IDEAS)
	{
		return -1;
	}
	return (long)&this->_ideas[index];
}

void	Brain::addIdea( const std::string & idea ) {

	this->_ideas[_idea_id] = idea;
	this->_idea_id++;
	if (this->_idea_id >= MAX_IDEAS)
	{
		this->_idea_id = 0;
	}
}

///			Constructor / Destructor

Brain::Brain( const std::string & first_idea )
: _ideas(), _idea_id(0) {

	if (Brain::_loud)
	{
  		std::cout << "[Brain] Specific constructor called" << std::endl;
	}
	this->_ideas[0] = first_idea;
	this->_idea_id++;
}

Brain::Brain( ) : _ideas(), _idea_id(0) {

	if (Brain::_loud)
	{
  		std::cout << "[Brain] Default constructor called" << std::endl;
	}
}

Brain::Brain( const Brain & other ) {

	if (Brain::_loud)
	{
  		std::cout << "[Brain] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

Brain::~Brain( ) {

	if (Brain::_loud)
	{
  		std::cout << "[Brain] Destructor called" << std::endl;
	}
}

Brain &	Brain::operator=( const Brain & rhs ) {

	if (Brain::_loud)
	{
  		std::cout << "[Brain] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
		{
			this->_ideas[i] = rhs.getIdea(i);
		}
	}
	return *this;
}

///			Functions / Methods

void	Brain::makeSilent( void ) {

	Brain::_loud = false;
}

///			Private:

std::ostream &  operator<<( std::ostream & o_stream, const Brain & brain ) {

	for (int i = 0; i < MAX_IDEAS; i++)
	{
		if (brain.getIdea(i).empty())
		{
			break;
		}
		o_stream << "idea(" << i << "): " << brain.getIdea(i) << std::endl;
	}
	return o_stream;
}

bool	Brain::_loud = true;
