#include "ScalarConverter.hpp"
#include <string>

///			Public:

///			Getters / Setters

int		ScalarConverter::getInt( ) const {

	return this->_int;
}

char	ScalarConverter::getChar( ) const {

	return this->_char;
}

float	ScalarConverter::getFloat( ) const {

	return this->_float;
}

double	ScalarConverter::getDouble( ) const {

	return this->_double;
}

///			Constructor / Destructor

ScalarConverter::ScalarConverter( const std::string & input ) : _input(input) {

	if (ScalarConverter::_loud)
	{
  		std::cout << "[ScalarConverter] Specific constructor called" << std::endl;
	}
	detectType();
	printType();
}

ScalarConverter::ScalarConverter( const ScalarConverter & other ) {

	if (ScalarConverter::_loud)
	{
  		std::cout << "[ScalarConverter] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	  // TODO
	}
}

ScalarConverter::~ScalarConverter( ) {

	if (ScalarConverter::_loud)
	{
  		std::cout << "[ScalarConverter] Destructor called" << std::endl;
	}
	// TODO
}

ScalarConverter &	ScalarConverter::operator=( const ScalarConverter & rhs ) {

	if (ScalarConverter::_loud)
	{
  		std::cout << "[ScalarConverter] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
			// TODO
	}
	return *this;
}

///			Functions / Methods


void	ScalarConverter::makeSilent( void ) {

	ScalarConverter::_loud = false;
}

///			Private:

std::string	ScalarConverter::castToInt( ) {


}

std::string	ScalarConverter::castToChar( ) {

}

std::string	ScalarConverter::castToDouble( ) {

}

std::string	ScalarConverter::castToFloat( ) {

}

void	ScalarConverter::printType( ) {

	switch (_type)
	{
		case INT:
			std::cout << "printing int: " << _int << std::endl;
			break;
		case CHAR:
			std::cout << "printing char: " << _char << std::endl;
			break;
		case DOUBLE:
			std::cout << "printing double: " << _double << std::endl;
			break;
		case FLOAT:
			std::cout << "printing float: " << _float << "f" << std::endl;
			break;
		default:
			std::cout << "<error printing>" << std::endl;
	}
}

std::string	ScalarConverter::castType( ) {

	switch (_type)
	{
		case INT:
			std::cout << "casting int: " << _int << std::endl;
			break;
		case CHAR:
			std::cout << "casting char: " << _char << std::endl;
			break;
		case DOUBLE:
			std::cout << "casting double: " << _double << std::endl;
			break;
		case FLOAT:
			std::cout << "casting float: " << _float << "f" << std::endl;
			break;
		default:
			std::cout << "<error printing>" << std::endl;
	}
}

bool	ScalarConverter::_loud = true;

void ScalarConverter::detectType() {

	if (_input.empty()) {
		std::cout << "empty input.." << std::endl;
		_type = DEFAULT;
		return ;
	}
	if (_input.size() == 1)
	{
		if (std::isdigit(_input[0]))
		{
			_type = INT;
			_int = std::stoi(_input);
			std::cout << "int found: '" << _input << "'" << std::endl;
		}
		else if (std::isprint(_input[0]))
		{
			_type = CHAR;
			_char = _input[0];
			std::cout << "char found: '" << _input << "'" << std::endl;
		}
		else
		{
			_type = DEFAULT;
			std::cerr << "unprintable char found: '" << _input << "'" << std::endl;
		}
		return ;
	}
	std::string::size_type	found = 0;
	while(isspace(_input[found]))
	{
		found++;
	}
	if (_input[0] == '-' || _input[0] == '+')
	{
		found++;
	}
	found = _input.find_first_not_of("0123456789", found);
	if (found == std::string::npos)
	{
		_type = INT;
		_int = std::stoi(_input);
		std::cout << "int found: '" << _input << "'" << std::endl;
		return ;
	}
	if (_input[found] == '.' && found > 0)
	{
		++found;
		if (_input[found] != '\0' && _input.find_first_not_of("0123456789", found) == std::string::npos)
		{
			_type = DOUBLE;
			_double = std::stod(_input);
			std::cout << "double found: '" << _input << "'" << std::endl;
			return ;
		}
		if (_input[_input.find_first_of('f') + 1] == '\0')
		{
			if (_input.find_first_not_of("0123456789f", found) == std::string::npos)
			{
				_type = FLOAT;
				_float = std::stof(_input);
				std::cout << "float found: '" << _input << "'" << std::endl;
				return ;
			}
		}
	}
	_type = DEFAULT;
	std::cerr << "->input unsupported: '" << _input << "'" << std::endl;
}

ScalarConverter::ScalarConverter( ) {

	if (ScalarConverter::_loud)
	{
  		std::cout << "[ScalarConverter] Default constructor called" << std::endl;
	}
}
